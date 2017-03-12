#include <stdio.h>
int main() {
    int n,i;
    scanf("%d",&n);
    long long t[n+1];
    t[0]=0;
    t[1]=2;
    for (i=2;i<=n;i++)
        t[i]=t[i-1]+t[i-2];
    printf("%Ld\n",t[n]); //неверный ответ на 12-ом тесте
    return 0;
}