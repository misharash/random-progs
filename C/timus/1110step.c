#include <stdio.h>
int powm(int x,int n,int m) {
    int r=1;
    x%=m;
    while (n) {
        if (n%2)
            r=(r*x)%m;
        n/=2;
        x=(x*x)%m;
    }
    return r;
}
int main() {
    int n,m,y;
    scanf("%d%d%d",&n,&m,&y);
    int i,j=0,v[m];
    for (i=1;i<m;i++)
        if (powm(i,n,m)==y) {
            v[j]=i;
            j++;
        }
    if (j) {
        for (i=0;i<j-1;i++)
            printf("%d ",v[i]);
        printf("%d\n",v[j-1]);
    }
    else
        printf("-1\n");
    return 0;
}