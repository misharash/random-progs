#include <stdio.h>
int main() {
  unsigned n,k,i,a,s=0;
  scanf("%u%u",&n,&k);
  for (i=0;i<k;i++) {
    scanf("%u",&a);
    s+=n-a;
    if (s>n)
      s=n;
  }
  s=n-s;
  printf("%u\n",s);
  return 0;
}

