#include <stdio.h>
int main() {
    long n;
    scanf("%ld",&n);
    int i,p=0,a=0,a2;
    for (i=1;i*(i+1)<=2*n;i++) {
        if (!((2*n)%i)) {
            a2=(2*n)/i-i+1;
            if (!(a2%2)) {
                p=i;
                a=a2/2;
            }
        }
    }
    printf("%d %d\n",a,p);
    return 0;
}