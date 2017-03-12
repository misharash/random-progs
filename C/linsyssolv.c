#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of variables: ");
    scanf("%d",&n);
    printf("Enter the coefficients (sum(ai*xi)+b=0):\n");
    int i,j;
    double coeff[n][n+1];
    for (i=0;i<n;i++) {
        printf("Eq.%d: ",i+1);
        for (j=0;j<=n;j++)
            scanf("%lf",&coeff[i][j]);
    }
    int k;
    i=0;
    for (i=0;i<n-1;i++) {
		if (coeff[i][i]==0)
			for (j=i+1;j<n;j++)
				if (coeff[j][i]!=0) {
					for (k=i;k<=n;k++)
						coeff[i][k]+=coeff[j][k];
					break;
				}
		if (coeff[i][i]==0) {
			printf("Exact solution doesn't exist.\n");
			return 0;
		}
        for (j=i+1;j<n;j++) {
            for (k=i+1;k<=n;k++)
				coeff[j][k]-=coeff[j][i]*coeff[i][k];
            coeff[j][i]=0;
        }
    }
    double sol[n],sum;
    for (i=n-1;i>=0;i--) {
        sum=coeff[i][n];
        for (j=i+1;j<n;j++)
            sum+=sol[j]*coeff[i][j];
        sol[i]=-sum/coeff[i][i];
    }
    for (i=0;i<n;i++)
        printf("x%d=%e\n",i+1,sol[i]);
    return 0;
}
