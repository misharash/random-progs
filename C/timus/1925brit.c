#include <stdio.h>
int main() {
    int b,g,n,k,i;
    scanf("%d%d",&n,&k);
    k-=2;
    for (i=0;i<n;i++) {
        scanf("%d%d",&b,&g);
        k+=b;
        k-=g+2;
    }
    if (k<0)
        printf("Big Bang!\n");
    else
        printf("%d\n",k);
    return 0;
}