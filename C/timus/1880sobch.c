#include <stdio.h>
#include <stdlib.h>
int main() {
    int n[3],i,j;
    int* s[3];
    for (i=0;i<3;i++) {
        scanf("%d",&n[i]);
        s[i]=(int*)calloc(n[i],sizeof(int));
        for (j=0;j<n[i];j++)
            scanf("%d",&s[i][j]);
    }
    int k,p=0,pp;
    for (i=0;i<n[0];i++) {
        pp=0;
        for (j=1;j<3;j++)
            for (k=0;k<n[j];k++)
                if (s[0][i]==s[j][k])
                    pp++;
        if (pp>=2)
            p++;
    }
    printf("%d\n",p);
    return 0;
}