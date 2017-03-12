#include <stdio.h>
int main() {
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (a>c) {
        printf("%d\n",a);
        return 0;
    }
    while (1) {
        if (a+b>c) {
            printf("%d\n",c);
            return 0;
        }
        a+=b;
        if (a>c-d) {
            printf("%d\n",a);
            return 0;
        }
        c-=d;
    }
}