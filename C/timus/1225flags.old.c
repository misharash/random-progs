#include <stdio.h>
long long t[46];
long long kvar(int n) {
    if (t[n]>0)
        return t[n];
    else
        return t[n]=kvar(n-2)+kvar(n-1);
}
int main() {
    int n,i;
    for (i=0;i<46;i++)
        t[i]=0;
    t[1]=1;
    t[2]=1;
    scanf("%d",&n);
    printf("%Ld\n",2*kvar(n));
    return 0;
}