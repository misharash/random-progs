#include <stdio.h>
typedef struct {
    int nfrom,nto;
    int from[1000],to[1000];
} node;
typedef struct {
    int from,to;
    double r;
} res;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    res rs[m];
    node nd[n];
    int i;
    for (i=0;i<n;i++) {
        nd[i].nto=0;
        nd[i].nfrom=0;
    }
    int j,p=n+m-1;
    double coeff[p][p+1];
    for (i=0;i<p;i++)
        for (j=0;j<=p;j++)
            coeff[i][j]=0;
    for (i=0;i<m;i++) {
        scanf("%d%d%lf",&rs[i].from,&rs[i].to,&rs[i].r);
        rs[i].from--;
        rs[i].to--;
        nd[rs[i].from].from[nd[rs[i].from].nfrom]=i;
        nd[rs[i].from].nfrom++;
        nd[rs[i].to].to[nd[rs[i].to].nto]=i;
        nd[rs[i].to].nto++;
        coeff[i][i]=rs[i].r;
        if (rs[i].from!=0)
            coeff[i][m+rs[i].from-1]=-1;
        if (rs[i].to!=0)
            coeff[i][m+rs[i].to-1]=1;
    }
    coeff[m][p]=-1;
    for (i=0;i<n-1;i++) {
        for (j=0;j<nd[i].nfrom;j++)
            coeff[m+i][nd[i].from[j]]=-1;
        for (j=0;j<nd[i].nto;j++)
            coeff[m+i][nd[i].to[j]]=1;
    }
    int k;
    for (i=0;i<p-1;i++) {
        for (j=i+1;j<p;j++) {
            for (k=i+1;k<=p;k++)
                coeff[j][k]=coeff[j][i]*coeff[i][k]-coeff[i][i]*coeff[j][k];
            coeff[j][i]=0;
        }
    }
    double ri=-coeff[p-1][p]/coeff[p-1][p-1];
    printf("%0.2lf\n",ri);
    return 0;
}