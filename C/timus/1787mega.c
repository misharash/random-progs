#include <stdio.h>
int neotr(int arg) {
    if (arg<0)
        return 0;
    return arg;
}
int main() {
    int k,n,a,p=0,i;
    scanf("%d%d",&k,&n);
    for (i=0;i<n;i++) {
        scanf("%d",&a);
        p+=a;
        p=neotr(p-k);
    }
    printf("%d\n",p);
    return 0;
}