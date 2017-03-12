#include <stdio.h>
#include <stdlib.h>
int ncmp(const void* a1,const void* a2) {
    if (*((unsigned*)a1)>*((unsigned*)a2))
        return 1;
    if (*((unsigned*)a1)==*((unsigned*)a2))
        return 0;
    return -1;
}
int main() {
    int n,i;
    scanf("%d",&n);
    unsigned k[n];
    for (i=0;i<n;i++)
        scanf("%u",&k[i]);
    qsort(k,n,sizeof(unsigned),ncmp);
    double med=((double) k[n/2])/2+((double) k[n/2-(n+1)%2])/2;
    printf("%0.1lf\n",med);
    return 0;
}
