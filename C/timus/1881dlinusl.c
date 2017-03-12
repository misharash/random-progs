#include <stdio.h>
#include <string.h>
int main() {
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    char s[w+1];
    int i,r=w,l,st=1;
    for (i=0;i<n;i++) {
        scanf("%s",s);
        l=strlen(s);
        if (r>=l)
            r-=l+1;
        else {
            r=w-l-1;
            st++;
        }
    }
    int p=st/h;
    if (st%h)
        p++;
    printf("%d\n",p);
    return 0;
}