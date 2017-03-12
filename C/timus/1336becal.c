#include <stdio.h>
int main() {
    long unsigned n;
    scanf("%lu",&n);
    long long unsigned n2=n;
    n2*=n;
    printf("%Lu\n%lu\n",n2,n);
    return 0;
}