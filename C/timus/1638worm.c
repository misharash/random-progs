#include <stdio.h>
int iabs(int arg) {
    if (arg>=0)
        return arg;
    else
        return -arg;
}
int main() {
    int w,h,n,k;
    scanf("%d%d%d%d",&w,&h,&n,&k);
    int s;
    s=iabs(w*(k-n-1)+2*h*(k-n));
    printf("%d\n",s);
    return 0;
}