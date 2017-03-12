#include <stdio.h>
int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    int i,xx,xp=2000,xo=-2000;
    for (i=0;i<n;i++) {
        scanf("%d",&xx);
        if ((xx>0)&&(xx<xp))
            xp=xx;
        if ((xx<0)&&(xx>xo))
            xo=xx;
    }
    if ((x<xo)||(x>xp)) {
        printf("Impossible\n");
        return 0;
    }
    int sp,so;
    if (x>0)
        printf("%d %d\n",x,x-2*xo);
    else
        printf("%d %d\n",2*xp-x,-x);
    return 0;
}