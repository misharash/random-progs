#include <stdio.h>
long double fac(int n) {
  long double r=1;
  for (i=2;i<=n;i++)
    r*=i;
  return r;
}
long double cnk(int n,int k) {
  return fac(n)/fac(k)/fac(n-k);
}
int main() {
  int n,m,N;
  scanf("%d%d%d",&n,&m,&N);
  int M[3];
  M[1]=rint(round
  return 0;
}
