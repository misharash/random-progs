#include <stdio.h>
#include <math.h>
typedef struct {
  int x,y,z;
} coords;
double sqr(double a) {
  return a*a;
}
double sqrt1(double a) {
  if (a<0)
    a=0;
  return sqrt(a);
}
double dist(coords a,coords b) {
  return sqrt(sqr(b.x-a.x)+sqr(b.y-a.y)+sqr(b.z-a.z));
}
double cat(double a,double b) {
  return sqrt1(sqr(a)-sqr(b));
}
double acos1(double a) {
  if (a>1)
    a=1;
  else
    if (a<-1)
      a=-1;
  return acos(a);
}
int main() {
  coords A,B,C;
  int R;
  scanf("%d%d%d%d%d%d%d%d%d%d",&A.x,&A.y,&A.z,&B.x,&B.y,&B.z,&C.x,&C.y,&C.z,&R);
  double AB=dist(A,B);
  if (AB<=0)
    printf("0.00\n");
  else {
    double BC=dist(B,C),AC=dist(A,C),p=(AB+BC+AC)/2,S=sqrt1(p*(p-AB)*(p-BC)*(p-AC)),CD=2*S/AB;
    if (CD>R)
      printf("%0.2lf\n",AB);
    else {
      double AD=cat(AC,CD),BD=cat(BC,CD);
      if ((AD>AB)||(BD>AB))
        printf("%0.2lf\n",AB);
      else {
        double l=cat(AC,R)+cat(BC,R)+R*(acos1((sqr(AC)+sqr(BC)-sqr(AB))/2/AC/BC)-acos1(R/AC)-acos1(R/BC));
        printf("%0.2lf\n",l);
      }
    }
  }
  return 0;
}
