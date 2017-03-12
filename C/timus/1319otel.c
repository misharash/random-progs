#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int t[n][n];
    int i,j,k=0;
    for (i=0;i<n;i++) {
        for (j=0;j<=i;j++) {
            k++;
            t[j][n-1-i+j]=k;
        }
    }
    for (i=n-2;i>=0;i--) {
        for (j=0;j<=i;j++) {
            k++;
            t[n-1-i+j][j]=k;
        }
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n-1;j++)
            printf("%d ",t[i][j]);
        printf("%d\n",t[i][j]);
    }
    return 0;
}
