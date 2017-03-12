#include <stdio.h>
#include <string.h>
int main() {
    long unsigned int n;
    scanf("%ld",&n);
    if (!n)
        printf("10\n");
    else
        if (n==1)
            printf("1\n");
        else {
            short unsigned int c=9;
            long long unsigned int q=0,t=1;
            while ((n!=1)&&(c>1)) {
                if (!(n%c)) {
                    q+=t*c;
                    n/=c;
                    t*=10; //Почему оно не работает полностью? Предположительно из-за этого
                }
                else
                    c--;
            }
            if (n==1)
                printf("%Ld\n",q);
            else
                printf("-1\n");
        }
}