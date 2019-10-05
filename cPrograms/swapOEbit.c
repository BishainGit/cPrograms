#include <stdio.h>
#include <string.h>

int swap(int num){
    int mask1 = 0xAAAAAAAA;
    int mask2 = 0x55555555;
    return(num << 1 & mask1)|(num >> 1 & mask2);

}

int maint(){
    int n;
   scanf("%d",&n);
   int ans = swap(n);
   printf("%d\n",n);
return 0;
}
