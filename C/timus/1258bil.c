#include <stdio.h>
#include <math.h>
int main() {
    int w,d;
    scanf("%d%d",&w,&d);
    int x0,y0;
    scanf("%d%d",&x0,&y0);
    int x1,y1;
    scanf("%d%d",&x1,&y1);
    char s[1010];
    scanf("%s",s);
    long long sx=x1-x0,sy=y1-y0;
    int s0x=0,s0y=0,s1x=0,s1y=0;
    int kx=-1,ky=-1;
    int i=0;
    while (s[i]!='\0') {
        switch (s[i]) {
            case 'L': {
                kx++;
                if (!(s0x))
                    s0x=x0;
                s1x=x1;
                break;
            }
            case 'R': {
                kx++;
                if (!(s0x))
                    s0x=w-x0;
                s1x=w-x1;
                break;
            }
            case 'F': {
                ky++;
                if (!(s0y))
                    s0y=y0;
                s1y=y1;
                break;
            }
            case 'B': {
                ky++;
                if (!(s0y))
                    s0y=d-y0;
                s1y=d-y1;
                break;
            }
        }
        i++;
    }
    if (kx>=0)
        sx=s0x+s1x+kx*w;
    if (ky>=0)
        sy=s0y+s1y+ky*d;
    double ss=sqrt(sx*sx+sy*sy);
    printf("%0.4f\n",ss);
    return 0;
}