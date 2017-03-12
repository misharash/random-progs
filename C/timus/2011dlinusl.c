#include <stdio.h>
int main() {
    int n,k[3],kk=0,k1=0,p=1,c,i;
    scanf("%d",&n);
    for (i=0;i<3;i++)
        k[i]=0;
    for (i=0;i<n;i++) {
        scanf("%d",&c);
        k[c-1]++;
    }
    for (i=0;i<3;i++)
        if (k[i]>0) {
            kk+=1;
            p*=k[i];
            if (k[i]>1)
                k1++;
        }
    if ((kk>=3)||((p>=4)&&(k1>=2))||((p>=5)&&(kk>=2)))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}