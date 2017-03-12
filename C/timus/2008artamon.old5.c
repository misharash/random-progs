#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define g 9.8
#define eps 0.000000000000001
float v,v2,v4;
typedef struct {
  float x,y;
} coords;
float sqr(float arg) {
  return arg*arg;
}
bool pryg(coords c1, coords c2) {
  float x=c2.x-c1.x,y=c2.y-c1.y;
  if (v2>g*(y+hypotf(x,y)))
    return true;
  return false;
}
int main() {
  scanf("%f",&v);
  v2=sqr(v);
  v4=sqr(v2);
  coords c[3];
  short i;
  for (i=0;i<3;i++)
    scanf("%f%f",&c[i].x,&c[i].y);
  if (pryg(c[1],c[2])&&pryg(c[2],c[1])&&(pryg(c[1],c[0])||pryg(c[2],c[0])))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}