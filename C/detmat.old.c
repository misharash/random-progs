#include <stdio.h>
double det(double* a, int n) {
	if (n==1)
		return *a;
	int i,j,k;
	double b[n][n-1][n-1],d=0;
	for (i=0;i<n;i++) {
		for (j=0;j<n-1;j++) {
			for (k=0;k<i;k++)
				b[i][j][k]=a[(j+1)*n+k];
			for (k=i;k<n-1;k++)
				b[i][j][k]=a[(j+1)*n+k+1];
		}
		d+=a[i]*(1-2*(i%2))*det(&b[i],n-1);
	}
	return d;
}
int main() {
	int n,i,j;
	printf("Введите порядок квадратной матрицы: ");
	scanf("%d",&n);
	double a[n][n];
	for (i=0;i<n;i++) {
		printf("Строка %d: ",i);
		for (j=0;j<n;j++)
			scanf("%lf",&a[i][j]);
	}
	printf("Определитель: %lf\n",det(a,n));
	return 0;
}
