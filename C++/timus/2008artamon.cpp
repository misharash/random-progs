#include <stdio.h>
#define g10 98
int v;
long long v2,v4;
typedef struct {
  int x,y;
} coords;
long long sqr(long long arg) {
  return arg*arg;
}
bool pryg(coords c1, coords c2) {
  int x=c2.x-c1.x,y=c2.y-c1.y;
  long long D=100*v4-20*g10*y*v2-sqr(g10)*sqr(x);
  //printf("%Ld\n",D);
  if (D>0)
    return true;
  return false;
}
int main() {
  scanf("%d",&v);
  v2=sqr(v);
  v4=sqr(v2);
  coords c[3];
  short i;
  for (i=0;i<3;i++)
    scanf("%d%d",&c[i].x,&c[i].y);
  if (pryg(c[1],c[2])&&pryg(c[2],c[1])&&(pryg(c[1],c[0])||pryg(c[2],c[0])))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}