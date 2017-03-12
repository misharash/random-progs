#include <stdio.h>
int main() {
  int n,i,a,ma=0,s=0;
  scanf("%d",&n);
  for (i=0;i<n;i++) {
    scanf("%d",&a);
    s+=a;
    if (a>ma)
      ma=a;
  }
  s+=ma;
  printf("%d\n",s);
  return 0;
}

