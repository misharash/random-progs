#include <stdio.h>
#include <stdbool.h>
#include <string.h>
short inot(short a) {
    if (a==0)
        return 1;
    return 0;
}
bool ishamming(short* c) {
    return (((c[1]+c[2]+c[3])%2==c[4])&&((c[0]+c[2]+c[3])%2==c[5])&&((c[0]+c[1]+c[3])%2==c[6]));
}
void printarr(short* a) {
    short i;
    for (i=0;i<6;i++)
        printf("%hd ",a[i]);
    printf("%hd\n",a[i]);
}
int main() {
    short i,h[7],nh[7];
    for (i=0;i<7;i++)
        scanf("%hd",&h[i]);
    if (ishamming(h))
        printarr(h);
    else
        for (i=0;i<7;i++) {
            memcpy(nh,h,7*sizeof(short));
            nh[i]=inot(nh[i]);
            if (ishamming(nh)) {
                printarr(nh);
                break;
            }
        }
    return 0;
}
        