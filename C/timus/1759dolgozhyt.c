#include <stdio.h>
long daynum(int d,int m,int y) {
    long r=d;
    int i;
    for (i=1800;i<y;i++) {
        r+=365;
        if ((!(i%4))&&(i%100))
            r+=1;
        if (!(i%400))
            r+=1;
    }
    for (i=1;i<m;i++) {
        if ((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12))
            r+=31;
        if ((i==4)||(i==6)||(i==9)||(i==11))
            r+=30;
        if (i==2) {
            r+=28;
            if ((!(y%4))&&(y%100))
                r+=1;
            if (!(y%400))
                r+=1;
        }
    }
    return r;
}
int main() {
    int n;
    scanf("%d",&n);
    int i,d[3],m[3],y[3],im=0;
    long l,lm=0;
    for (i=1;i<=n;i++) {
        scanf("%d.%d.%d %d.%d.%d %d.%d.%d",&d[0],&m[0],&y[0],&d[1],&m[1],&y[1],&d[2],&m[2],&y[2]);
        l=daynum(d[2],m[2],y[2])-daynum(d[0],m[0],y[0]);
        if (l>lm) {
            lm=l;
            im=i;
        }
    }
    printf("%d\n",im);
    return 0;
}