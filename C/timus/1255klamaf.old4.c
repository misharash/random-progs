#include <stdio.h>
long count(int n1,int n2,int k) {
    if ((n1<k)&&(n2<k))
        return 0;
    if (n1>n2) {
        if (n2>=k)
            return n1+count(n1,n2-k,k);
        return n2+count(n1-k,n2,k);
    }
    return n1+count(n1,n2-k,k);
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    long g=count(n,n,k);
    printf("%ld\n",g);
    return 0;
}