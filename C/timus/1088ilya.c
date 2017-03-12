#include <stdio.h>
int main() {
    int d,e,f,h;
    long long dp,ep;
    scanf("%d%d%d%Ld%Ld%d",&d,&e,&f,&dp,&ep,&h);
    dp--;
    ep--;
    int dm[f],em[f],i;
    for (i=0;i<f;i++) {
        dm[i]=dp%2;
        dp/=2;
        em[i]=ep%2;
        ep/=2;
    }
    int g;
    for (g=f-1;dm[g]==em[g];g--);
    g++;
    int r;
    if ((g>d)&&(g>e))
        r=2*g-d-e;
    else
        if (d>e)
            r=d-e;
        else
            r=e-d;
    if (r<=h)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}