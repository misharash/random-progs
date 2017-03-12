#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int t[n][n];
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            scanf("%d",&t[i][j]);
    for (i=0;i<n;i++)
        for (j=0;j<=i;j++)
            printf("%d ",t[i-j][j]);
    for (i=n-2;i>0;i--)
        for (j=0;j<=i;j++)
            printf("%d ",t[n-1-j][n-1-i+j]);
   if (n>1)
        printf("%d\n",t[n-1][n-1]);
    return 0;
}
