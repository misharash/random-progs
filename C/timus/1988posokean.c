#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define prec 0.0000001
typedef struct {
  double x,y,z;
} coords;
double v,a0,r,d,r2,d2,v2,rd;
double sqr(double a) {
  return a*a;
}
double sqrt1(double a) {
  if (a<0)
    return 0;
  return sqrt(a);
}
double cat(double a,double b) {
  return sqrt1(sqr(a)-sqr(b));
}
double acos1(double a) {
  if (a>1)
    return 0;
  if (a<-1)
    return M_PI;
  return acos(a);
}
double absv(coords a) {
  return sqrt1(sqr(a.x)+sqr(a.y)+sqr(a.z));
}
double scpv(coords a,coords b) {
  return a.x*b.x+a.y*b.y+a.z*b.z;
}
double f(double a) {
  return 2*rd*cos(a0-a)+r2*v2*sqr(a)-d2-r2;
}
double root(double x0,double x1) {
  double f0=f(x0),f1,delta;
  do {
    //printf("%lf %lf\n",x0,x1);
    f1=f(x1);
    delta=(x1-x0)*f1/(f1-f0);
    //printf("%lf\n",delta);
    x0=x1;
    f0=f1;
    x1-=delta;
  } while (fabs(delta)*r>prec);
  return x1;
}
int main() {
  coords kk,av;
  scanf("%lf%lf%lf%lf%lf%lf%lf",&av.x,&av.y,&av.z,&kk.x,&kk.y,&kk.z,&v);
  v2=sqr(v);
  d=absv(kk);
  r=absv(av);
  d2=sqr(d);
  r2=sqr(r);
  rd=r*d;
  a0=acos1(scpv(kk,av)/rd);
  double t1=(d-r)/v,t2=r*a0,t;
  if (t1>=t2)
    t=t1;
  else {
    double a1=acos1(r/d);
    if (a1>a0)
      t=r*root(0,a0);
    else {
      t1=cat(d,r)/v;
      t2=(a0-a1)*r;
      if (t1<t2)
        t=t1+(t2-t1)/(1+v);
      else
        t=r*root(0,a1);
    }
  }
  printf("%0.6lf\n",t);
  return 0;
}
