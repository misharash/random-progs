#include <stdio.h>
#include <stdlib.h>
int ncmp(const void* a,const void* b) {
    return *(int*)b-*(int*)a;
}
int main() {
    int n,i;
    scanf("%d",&n);
    int p[n];
    for (i=0;i<n;i++)
        scanf("%d",&p[i]);
    qsort(p,n,sizeof(int),ncmp);
    for (i=0;i<n;i++)
        printf("%d\n",p[i]);
    return 0;
}