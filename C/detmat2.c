#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double det(double **a, int n) {
	int i,j,k;
	double **b,*area,d=1;
	area=malloc(n*n*sizeof(double));
	b=malloc(n*sizeof(double*));
	for (i=0;i<n;i++) {
		b[i]=area+n*i;
		memcpy(b[i],a[i],n*sizeof(double));
	}
	for (i=0;i<n;i++) {
		if (b[i][i]==0)
			for (j=i+1;j<n;j++)
				if (b[j][i]!=0) {
					for (k=i;k<n;k++)
						b[i][k]+=b[j][k];
					break;
				}
		if (b[i][i]==0)
			return 0;
		for (j=i+1;j<n;j++)
			if (b[j][i]!=0) {
				for (k=i+1;k<n;k++)
					b[j][k]-=b[j][i]*b[i][k];
				b[j][i]=0;
			}
	}
	for (i=0;i<n;i++)
		d*=b[i][i];
	free(b);
	free(area);
	return d;
}
int main() {
	int n,i,j;
	printf("Введите порядок квадратной матрицы: ");
	scanf("%d",&n);
	double **a,*area;
	area=malloc(n*n*sizeof(double));
	a=malloc(n*sizeof(double*));
	for (i=0;i<n;i++) {
		a[i]=area+n*i;
		printf("Строка %d: ",i);
		for (j=0;j<n;j++)
			scanf("%lf",&a[i][j]);
	}
	printf("Определитель: %lf\n",det(a,n));
	free(area);
	free(a);
	return 0;
}
