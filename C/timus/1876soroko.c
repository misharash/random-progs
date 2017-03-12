#include <stdio.h>
int main() {
    short int a,b;
    scanf("%d%d",&a,&b);
    //Все правые попробовать на левые: 40+2*b
    //39 правых попробовать на левые, а потом попробовать все оставшиеся левые на правые: 78+40+2*(a-40)+1
    short int r1=40+2*b,r2=39+2*a;
    if (r1>r2)
        printf("%d\n",r1);
    else
        printf("%d\n",r2);
    return 0;
}