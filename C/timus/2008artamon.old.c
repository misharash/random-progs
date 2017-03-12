#include <stdio.h>
#include <stdbool.h>
#define g 9.8
#define eps 0.0000001
double v,v2,v4;
typedef struct {
  double x,y;
} coords;
double sqr(double arg) {
  return arg*arg;
}
bool pryg(coords c1, coords c2) {
  double x=c2.x-c1.x,y=c2.y-c1.y;
  double D=1-2*g*y/v2-sqr(g)*sqr(x)/v4;
  //printf("%lf\n",D);
  if (D>-eps)
    return true;
  return false;
}
int main() {
  scanf("%lf",&v);
  v2=sqr(v);
  v4=sqr(v2);
  coords c[3];
  short i;
  for (i=0;i<3;i++)
    scanf("%lf%lf",&c[i].x,&c[i].y);
  if (pryg(c[1],c[2])&&pryg(c[2],c[1])&&(pryg(c[1],c[0])||pryg(c[2],c[0])))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}