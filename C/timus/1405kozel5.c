#include <stdio.h>
#include <math.h>
typedef struct {
	double x,y;
} coords;
double sqr(double a) {
	return a*a;
}
double dist(coords a,coords b) {
	return hypot(b.x-a.x,b.y-a.y);
}
int main() {
	int n,i,j;
	scanf("%d",&n);
	coords d[n];
	double dd[n][n],md[n],s=0,mdm,r1,r2;
	for (i=0;i<n;i++)
		scanf("%lf%lf",&d[i].x,&d[i].y);
	for (i=0;i<n;i++) {
		dd[i][i]=0;
		md[i]=1000;
		for (j=0;j<i;j++)
			md[i]=fmin(md[i],dd[i][j]);
		for (j=i+1;j<n;j++) {
			dd[i][j]=dist(d[i],d[j]);
			dd[j][i]=dd[i][j];
			md[i]=fmin(md[i],dd[i][j]);
		}
	}
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++) {
			r1=fmax(md[i],md[j]);
			if (r1>0.999999999) {
				mdm=md[i]+md[j]-r1;
				if (mdm>0.999999999) {
					r1=fmin(r1,50);
					r2=fmin(dd[i][j]-r1,mdm);
					r2=fmin(r2,50);
					r2=fmax(r2,1);
					r1=fmin(r1,dd[i][j]-r2);
					s=fmax(s,(sqr(r1)+sqr(r2))*M_PI);
				}
			}
			//printf("%d %d %lf %lf %lf %lf %lf %lf\n",i,j,md[i],md[j],dd[i][j],r1,r2,s);
		}
	printf("%0.4lf\n",s);
	return 0;
}