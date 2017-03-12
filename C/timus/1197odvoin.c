#include <stdio.h>
#define N 8
int kpb(char* s) {
    int r=0,x=(int)s[0]-96,y=(int)s[1]-48;
    if ((x-2>0)&&(y-1>0))
        r++;
    if ((x-2>0)&&(y+1<=N))
        r++;
    if ((x+2<=N)&&(y+1<=N))
        r++;
    if ((x+2<=N)&&(y-1>0))
        r++;
    if ((y-2>0)&&(x-1>0))
        r++;
    if ((y-2>0)&&(x+1<=N))
        r++;
    if ((y+2<=N)&&(x+1<=N))
        r++;
    if ((y+2<=N)&&(x-1>0))
        r++;
    return r;
}
int main() {
    int n;
    scanf("%d",&n);
    int i;
    char s[3];
    for (i=0;i<n;i++) {
        scanf("%s",s);
        printf("%d\n",kpb(s));
    }
    return 0;
}

