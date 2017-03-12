#include <stdio.h>
int main() {
    unsigned int n,k;
    scanf("%d%d",&n,&k);
    if (k>n)
        printf("2\n");
    else {
        int r=(2*n)/k;
        if ((2*n)%k)
            r++;
        printf("%d\n",r);
    }
    return 0;
}