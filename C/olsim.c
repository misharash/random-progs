#include <stdio.h>
#include <math.h>
#include <string.h>
int main() {
	int n;
	printf("Введите количество точек: ");
	scanf("%d",&n);
	long double x[n],y[n],sx[n],sy[n];
	int i;
	printf("Вводите точки в формате X sX Y sY.\n");
	for (i=0;i<n;i++) {
		printf("%d: ",i+1);
		scanf("%Lf%Lf%Lf%Lf",&x[i],&sx[i],&y[i],&sy[i]);
	}
	char ask[10];
	printf("Нужна корректировка точек (д/Н)? ");
	scanf("%s",ask);
	while ((!strcmp(ask,"Д"))||(!strcmp(ask,"д"))) {
		printf("Введите номер пары: ");
		scanf("%d",&i);
		printf("%d: ",i);
		i--;
		scanf("%Lf%Lf%Lf%Lf",&x[i],&sx[i],&y[i],&sy[i]);
		printf("Нужна корректировка точек (д/Н)? ");
		scanf("%s",ask);
	}
	long double Sx,Sy,Sx2,Sy2,Sxy,Ss,v,a=0,ax,ay,ax2,ay2,axy;
	int j;
	for (j=0;j<3;j++) {
		Sx=0;
		Sy=0;
		Sx2=0;
		Sy2=0;
		Sxy=0;
		Ss=0;
		for (i=0;i<n;i++) {
			v=1/(sy[i]*sy[i]+a*a*sx[i]*sx[i]);
			Sx+=x[i]*v;
			Sy+=y[i]*v;
			Sx2+=(x[i]*x[i]+sx[i]*sx[i])*v;
			Sy2+=(y[i]*y[i]+sy[i]*sy[i])*v;
			Sxy+=x[i]*y[i]*v;
			Ss+=v;
		}
		ax=Sx/Ss;
		ay=Sy/Ss;
		ax2=Sx2/Ss;
		ay2=Sy2/Ss;
		axy=Sxy/Ss;
		a=(axy-ax*ay)/(ax2-ax*ax);
	}
	long double b=(ax2*ay-ax*axy)/(ax2-ax*ax);
	long double chi2=0;
	for (i=0;i<n;i++)
		chi2+=(y[i]-a*x[i]-b)*(y[i]-a*x[i]-b)/(sy[i]*sy[i]+a*a*sx[i]*sx[i]);
	long double s02=(long double)n/(n-2)*(ay2-ay*ay-(axy-ax*ay)*(axy-ax*ay)/(ax2-ax*ax));
	long double sa2=s02/n/(ax2-ax*ax);
	long double sb2=sa2*ax2;
	long double sa=sqrtl(sa2),sb=sqrtl(sb2);
	printf("y=ax+b\n");
	printf("a=%Le±%Le\n",a,sa);
	printf("b=%Le±%Le\n",b,sb);
	printf("chi2=%Lf (must be %d±%lf)\n",chi2,n-2,sqrt(2*(n-2)));
	return 0;
}