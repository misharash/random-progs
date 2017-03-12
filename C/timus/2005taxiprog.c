#include <stdio.h>
int main() {
    int i,j,d[5][5];
    for (i=0;i<5;i++)
        for (j=0;j<5;j++)
            scanf("%d",&d[i][j]);
    char* r="1 2 3 4 5";
    int s=d[0][1]+d[1][2]+d[2][3]+d[3][4],sm=s;
    s=d[0][3]+d[3][2]+d[2][1]+d[1][4];
    if (s<sm) {
        r="1 4 3 2 5";
        sm=s;
    }
    s=d[0][2]+d[2][1]+d[1][3]+d[3][4];
    if (s<sm) {
        r="1 3 2 4 5";
        sm=s;
    }
    s=d[0][2]+d[2][3]+d[3][1]+d[1][4];
    if (s<sm) {
        r="1 3 4 2 5";
        sm=s;
    }
    printf("%d\n%s\n",sm,r);
    return 0;
}