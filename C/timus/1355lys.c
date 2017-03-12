#include <stdio.h>
int main() {
    int t,a,b,c,cc,n,p,i;
    scanf("%d",&t);
    for (i=0;i<t;i++) {
        scanf("%d%d",&a,&b);
        p=0;
        if (!(b%a)) {
            p=1;
            c=a;
            n=2;
            while ((c<b)&&(n*n<=b)) {
                cc=c*n;
                while ((!(b%cc))&&(c<b)) {
                    c=cc;
                    cc*=n;
                    p++;
                }
                n++;
            }
            if (c<b)
                p++;
        }
        printf("%d\n",p);
    }
    return 0;
}