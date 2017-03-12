#include <stdio.h>
int iabs(int arg) {
    if (arg<0)
        return -arg;
    return arg;
}
int main() {
    int n;
    scanf("%d",&n);
    int p=0,pp,i,k=0;
    char s[20];
    for (i=0;i<n;i++) {
        pp=p;
        scanf("%s",s);
        if ((s[0]=='A')||(s[0]=='P')||(s[0]=='O')||(s[0]=='R'))
            p=0;
        else
            if ((s[0]=='B')||(s[0]=='M')||(s[0]=='S'))
                p=1;
            else
                p=2;
        k+=iabs(p-pp);
    }
    printf("%d\n",k);
    return 0;
}