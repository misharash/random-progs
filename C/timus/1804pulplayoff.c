#include <stdio.h>
int main() {
  int t,i,x,y,ming,maxg;
  scanf("%d",&t);
  char s[100],w;
  gets(s);
  for (i=0;i<t;i++) {
    gets(s);
    sscanf(s,"The Machinegunners played %c%*c%*c%*c game, scored %d goals, and conceded %d goals.",&w,&x,&y);
    ming=y-x;
    maxg=30+y-x;
    if (w=='h') {
      if (ming<y)
        ming+=1;
      if (maxg>y)
        maxg-=1;
    }
    if (ming<0)
      ming=0;
    if (maxg>30)
      maxg=30;
    printf("%d %d\n",ming,maxg);
  }
  return 0;
}
