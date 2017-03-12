#include <stdio.h>
#include <math.h>
#define prec 0.000001
typedef struct {
  int x,y;
} coords;
double sqr(double a) {
  return a*a;
}
int isqr(int a) {
  return a*a;
}
int sqdist(coords a,coords b) {
  return isqr(b.x-a.x)+isqr(b.y-a.y);
}
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
double str(double a,double b,double c) {
  double p=(a+b+c)/2;
  return sqrt1(p*(p-a)*(p-b)*(p-c));
}
double cat(double a2,double b) {
  return sqrt1(a2-sqr(b));
}
int main() {
  coords s;
  int n,i;
  scanf("%d%d%d",&s.x,&s.y,&n);
  coords v[n];
  for (i=0;i<n;i++)
    scanf("%d%d",&v[i].x,&v[i].y);
  int d1s=sqdist(s,v[n-1]),d2s=sqdist(s,v[0]),d3s=sqdist(v[0],v[n-1]);
  double d1=sqrt(d1s),d2=sqrt(d2s),d3=sqrt(d3s),sa=acos1((d1s+d2s-d3s)/2/d1/d2),h=2*str(d1,d2,d3)/d3,p1=cat(d1s,h),p2=cat(d2s,h),hm;
  if ((p1>d3)||(p2>d3))
    hm=fmin(d1,d2);
  else
    hm=h;
  for (i=0;i<n-1;i++) {
    d1s=sqdist(s,v[i]);
    d2s=sqdist(s,v[i+1]);
    d3s=sqdist(v[i],v[i+1]);
    d1=sqrt(d1s);
    d2=sqrt(d2s);
    d3=sqrt(d3s);
    sa+=acos1((d1s+d2s-d3s)/2/d1/d2);
    h=2*str(d1,d2,d3)/d3;
    p1=cat(d1s,h);
    p2=cat(d2s,h);
    //printf("%lf %lf %lf %lf %lf %lf\n",h,p1,p2,d1,d2,sa);
    if ((p1>d3)||(p2>d3))
      hm=fmin(hm,fmin(d1,d2));
    else
      hm=fmin(hm,h);
  }
  hm*=2;
  if (sa>2*M_PI-prec)
    hm=0;
  printf("%0.3lf\n",hm);
  return 0;
}
