#include <stdio.h>
#include <math.h>
double sqrt1(double a) {
	if (a<0)
		return 0;
	return sqrt(a);
}
double acos1(double a) {
	if (a>1)
		return 0;
	if (a<-1)
		return M_PI;
	return acos(a);
}
double cat(double a,double b) {
	return sqrt1(a*a-b*b);
}
int rint1(double a) {
	int r=lround(a);
	if (a-r>0)
		r++;
	return r;
}
int main() {
	double h,d,a,l=0,ol;
	scanf("%lf%lf%lf",&h,&d,&a);
	int k=rint1(h/d),i;
	double a2=a/2,xx=0,zz=h,x[k+1],z[k+1],cosa=cos(a),sina=sin(a),sina2=sin(a2),cosa2=cos(a2);
	for (i=0;(zz<(k-i)*d)&&(zz>0);i++) {
		x[i]=xx;
		z[i]=zz;
		ol=l;
		l=l*cosa+cat(d,l*sina);
		if (l<=ol) {
			i++;
			break;
		}
		xx=l*sina2*(2*(i%2)-1);
		zz=h-l*cosa2;
		//printf("%lf %lf %lf\n",l,xx,zz);
	}
	if (zz<0)
		printf("-1\n");
	else {
		i--;
		xx=x[i];
		zz=z[i];
		zz=d*(k-i-1);
		xx+=cat(d,z[i]-zz)*(1-2*(i%2)) ;
		i++;
		x[i]=xx;
		z[i]=zz;
		for (i++;i<=k;i++) {
			x[i]=xx;
			z[i]=d*(k-i);
		}
		printf("%d\n",k);
		for (i=1;i<=k;i++)
			printf("%lf 0 %lf\n",x[i],z[i]);
	}
	return 0;
}
