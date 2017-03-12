#include <stdio.h>
int main() {
    int n,c,pc,i,k=1;
    scanf("%d",&n);
    scanf("%d",&c);
    for (i=1;i<n;i++) {
        pc=c;
        scanf("%d",&c);
        if (c==pc)
            k++;
        else {
            printf("%d %d ",k,pc);
            k=1;
        }
    }
    printf("%d %d\n",k,c);
    return 0;
}
