#include <stdio.h>
int sqr(int a) {
	return a*a;
}
char sgn(int a) {
	if (a>0)
		return 1;
	if (a<0)
		return -1;
	return 0;
}
int main() {
	int d,d2,x1,y1,x2,y2,n,i,x,y,r2;
	scanf("%d%d%d%d%d%d",&d,&x1,&y1,&x2,&y2,&n);
	d2=sqr(d);
	if (x1*y2==x2*y1)
		for (i=0;i<n;i++) {
			scanf("%d%d",&x,&y);
			r2=sqr(x)+sqr(y);
			if ((r2==0)||((r2<=d2)&&(x1*y-y1*x==0)&&(sgn(x)==sgn(x1))&&(sgn(y)==sgn(y1))))
				printf("YES\n");
			else
				printf("NO\n");
		}
	else
		for (i=0;i<n;i++) {
			scanf("%d%d",&x,&y);
			if ((sqr(x)+sqr(y)<=d2)&&(x1*y-y1*x>=0)&&(x2*y-y2*x<=0))
				printf("YES\n");
			else
				printf("NO\n");
		}
	return 0;
}
