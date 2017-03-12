#include <stdio.h>
#include <stdbool.h>
bool e[51][501];
long long k[51][501];
long long kb(int n,int s) {
    if (e[n][s])
        return k[n][s];
    int i;
    long long r=0;
    for (i=0;(i<10)&&(i<=s);i++)
        r+=kb(n-1,s-i);
    e[n][s]=true;
    printf("%d %d %Ld\n",n,s,r);
    return k[n][s]=r;
}
__int128 isqr(long long a) {
    return a*a;
}
int main() {
    int n,s;
    scanf("%d%d",&n,&s);
    if (s%2)
        printf("0\n");
    else {
        s/=2;
        int i,j;
        for (i=0;i<501;i++) {
            e[0][i]=true;
            k[0][i]=0;
        }
        k[0][0]=1;
        for (i=1;i<51;i++)
            for (j=0;j<501;j++)
                e[i][j]=false;
        printf("%Ld\n",isqr(kb(n,s)));
    }
    return 0;
}