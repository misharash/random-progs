#include <stdio.h>
int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    int i,f[b-a+1];
    for (i=0;i<=b-a;i++)
        scanf("%d",&f[i]);
    int k=1,kp=0;
    for (i=1;i<b-a;i++)
        if (((f[i]>f[i-1])&&(f[i]>f[i+1]))||((f[i]<f[i-1])&&(f[i]<f[i+1]))) {
            k+=1-kp;
            kp=0;
        }
        else
            if ((f[i]==f[i-1])||(f[i]==f[i+1])) {
                k+=1-kp;
                kp=1;
            }
            else
                kp=0;
    printf("%d\n",k);
    return 0;
}