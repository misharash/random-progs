#include <stdio.h>
int cycle(int current,int target,int poc[]) {
    if (poc[current]==target)
        return 1;
    if (poc[current]==-1)
        return 0;
    return cycle(poc[current],target,poc);
}
int test() {
    int n;
    scanf("%d",&n);
    int p[n],i,ks=0,kc=0;
    for (i=0;i<n;i++) {
        scanf("%d",&p[i]);
        p[i]--;
    }
    for (i=0;i<n;i++) {
        if (p[i]==-1)
            ks++;
        else
            kc+=cycle(i,i,p);
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