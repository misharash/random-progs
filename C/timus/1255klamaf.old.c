#include <stdio.h>
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    long g=(n+n%k)*(n/k);
    printf("%ld\n",g);
    return 0;
}