#include <stdio.h>
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int g=n+n%k*n/k;
    printf("%d\n",g);
    return 0;
}