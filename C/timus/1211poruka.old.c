#include <stdio.h>
int cycle(int current,int target,int poc[],short int nvis[]) {
    if (!nvis[current])
        return 0;
    nvis[current]=0;
    if (poc[current]==target)
        return 1;
    if (poc[current]==-1)
        return 0;
    return cycle(poc[current],target,poc,nvis);
}
int test() {
    int n;
    scanf("%d",&n);
    int p[n],i,ks=0,kc=0;
    short int nv[n];
    for (i=0;i<n;i++) {
        scanf("%d",&p[i]);
        p[i]--;
        nv[i]=1;
    }
    for (i=0;i<n;i++) {
        if (p[i]==-1)
            ks++;
        else
            if (nv[i])
                kc+=cycle(i,i,p,nv);
        if ((ks>1)||(kc>0)) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
int main() {
    int t,tt;
    scanf("%d",&t);
    for (tt=0;tt<t;tt++) {
        test();
    }
    return 0;
}