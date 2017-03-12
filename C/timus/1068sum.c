#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    long sum;
    if (n>0)
        sum=n*(n+1)/2;
    else
        sum=1-n*(n-1)/2;
    printf("%ld\n",sum);
    return 0;
}