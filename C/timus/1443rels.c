#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int s1,s2,l1,l2;
    scanf("%d.%d",&s1,&s2);
    scanf("%d.%d",&l1,&l2);
    int ss=10000*s1+s2,ll=10000*l1+l2,k1=ss/ll,lll=ss%ll,k=n*k1;
    if (lll!=0) {
        int k2=ll/lll;
        k+=n/k2;
        if (n%k2)
            k++;
    }
    printf("%d\n",k);
    return 0;
}
