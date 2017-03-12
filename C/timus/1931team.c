#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    unsigned long a;
    scanf("%ld",&a);
    unsigned long b=a;
    int c[n];
    c[0]=0;
    int i,p=0;
    for (i=1;i<n;i++) {
        c[i]=1;
        c[p]++;
        scanf("%ld",&a);
        if (a<b) {
            b=a;
            p=i;
        }
    }
    p=0;
    for (i=0;i<n;i++)
        if (c[i]>c[p])
            p=i;
    printf("%d\n",p+1);
    return 0;
}