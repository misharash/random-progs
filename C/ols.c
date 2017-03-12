#include <stdio.h>
#include <math.h>
#include <string.h>
int main() {
	int n;
	printf("Введите количество точек: ");
	scanf("%d",&n);
	long double x[n],y[n];
	int i;
	printf("Вводите точки в формате X Y.\n");
	for (i=0;i<n;i++) {
		printf("%d: ",i+1);
		scanf("%Lf%Lf",&x[i],&y[i]);
	}
	char ask[10];
	printf("Нужна корректировка точек (д/Н)? ");
	scanf("%s",ask);
	while ((!strcmp(ask,"Д"))||(!strcmp(ask,"д"))) {
		printf("Введите номер пары: ");
		scanf("%d",&i);
		printf("%d: ",i);
		i--;
		scanf("%Lf%Lf",&x[i],&y[i]);
		printf("Нужна корректировка точек (д/Н)? ");
		scanf("%s",ask);
	}
	long double sx=0,sy=0,sx2=0,sy2=0,sxy=0;
	for (i=0;i<n;i++) {
		sx+=x[i];
		sy+=y[i];
		sx2+=x[i]*x[i];
		sy2+=y[i]*y[i];
		sxy+=x[i]*y[i];
	}
	long double ax=sx/n,ay=sy/n,ax2=sx2/n,ay2=sy2/n,axy=sxy/n;
	long double a=(axy-ax*ay)/(ax2-ax*ax);
	long double b=(ax2*ay-ax*axy)/(ax2-ax*ax);
	long double s02=(long double)n/(n-2)*(ay2-ay*ay-(axy-ax*ay)*(axy-ax*ay)/(ax2-ax*ax));
	long double sa2=s02/n/(ax2-ax*ax);
	long double sb2=sa2*ax2;
	long double da=sqrtl(sa2),db=sqrtl(sb2);
	printf("y=ax+b\n");
	printf("a=%Le±%Le\n",a,da);
	printf("b=%Le±%Le\n",b,db);
}