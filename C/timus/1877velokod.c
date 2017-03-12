#include <stdio.h>
int main() {
    int c1,c2;
    scanf("%d%d",&c1,&c2);
    if ((!(c1%2))||(c2%2))
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
