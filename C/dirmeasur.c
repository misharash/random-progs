#include <stdio.h>
#include <math.h>
int main() {
    int n;
    printf("Enter the number of measurements: ");
    scanf("%d",&n);
    double x[n];
    printf("Enter the results.\n");
    int i;
    for (i=0;i<n;i++) {
        printf("%d: ",i+1);
        scanf("%lf",&x[i]);
    }
    printf("Do you need to correct the values (y/N)? ");
    char c[10];
    scanf("%s",&c);
    while ((!strcmp(c,"y"))||(!strcmp(c,"Y"))) {
        printf("Enter the number of value you want to correct: ");
        scanf("%d",&i);
        printf("%d: ",i+1);
        scanf("%lf",&x[i]);
        printf("Do you need to correct the values (y/N)? ");
        scanf("%s",&c);
    }
    double sum=0;
    for (i=0;i<n;i++)
        sum+=x[i];
    double xa=sum/n;
    printf("Average: %e\n",xa);
    double sum2o=0;
    for (i=0;i<n;i++)
        sum2o+=(x[i]-xa)*(x[i]-xa);
    double a2o=sum2o/n;
    double sigma=sqrt(a2o);
    printf("Sigma: %e\n",sigma);
    double dx=3*sigma/sqrt(n-1);
    printf("dx: %e\n",dx);
    return 0;
}