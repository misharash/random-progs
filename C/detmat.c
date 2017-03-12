#include <stdio.h>
#include <stdlib.h>
double det(double** a, int n) {
	if (n==1)
		return **a;
	int i,j,k;
	double **b,*area,d=0;
	b=malloc((n-1)*sizeof(double*));
	area=malloc((n-1)*(n-1)*sizeof(double));
	for (i=0;i<n;i++) {
		for (j=0;j<n-1;j++) {
			b[j]=area+j*(n-1);
			for (k=0;k<i;k++)
				b[j][k]=a[j+1][k];
			for (k=i;k<n-1;k++)
				b[j][k]=a[j+1][k+1];
		}
		d+=a[0][i]*(1-2*(i%2))*det(b,n-1);
	}
	free(area);
	free(b);
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
