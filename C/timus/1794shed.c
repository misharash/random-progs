#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a,i,k[n];
    for (i=0;i<n;i++)
        k[i]=0;
    for (i=0;i<n;i++) {
        scanf("%d",&a);
        k[(i+1-a+2*n)%n]++;
    }
    int imax=0;
    for (i=1;i<n;i++)
        if (k[i]>k[imax])
            imax=i;
    printf("%d\n",imax+1);
    return 0;
}