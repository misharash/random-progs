#include <stdio.h>
#include <math.h>
int main() {
    int a,l;
    scanf("%d%d",&a,&l);
    float s;
    if (2*l*l>=a*a)
        s=a*a;
    else
        if (2*l<=a)
            s=M_PI*l*l;
        else {
            float d=((float) a)/2;
            float sk=M_PI*l*l;
            float ss=l*l*acosf(d/l)-d*sqrtf(l*l-d*d);
            s=sk-4*ss;
        }
    printf("%0.3f\n",s);
    return 0;
}