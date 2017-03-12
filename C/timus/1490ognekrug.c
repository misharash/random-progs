#include <stdio.h>
#include <math.h>
long long sqr(int a) {
	return (long long)a*a;
}
int cat(int a, int b) {
	long long s=sqr(a)-sqr(b);
	int c=lrint(sqrt(s));
	while (sqr(c-1)>=s)
		c--;
	while (sqr(c)<s)
		c++;
	return c;
}
int cat2(long long a) {
	double s=(double)a/2;
	int c=lrint(sqrt(s));
	while (sqr(c-1)>=s)
		c--;
	while (sqr(c)<s)
		c++;
	return c;
}
long long xint(int a, int b) {
	return (long long)a*b;
}
int main() {
	int r,l=0,lp=0,i;
	long long k=0,r2;
	scanf("%d",&r);
	r2=sqr(r);
	for (i=r-1;2*sqr(i)>=r2;i--) {
		lp=l;
		l=cat(r,i);
		//printf("%d\n",l);
		k+=xint(l-lp,2*i+2-l-lp);
		//printf("%lld\n",xint(l-lp,2*i+2-l-lp));
	}
	lp=l;
	l=cat2(r2);
	//printf("%d\n",l);
	k+=xint(l-lp,2*i+2-l-lp);
	//printf("%lld\n",xint(l-lp,2*i+2-l-lp));
	//printf("%lld\n",k);
	k*=4;
	printf("%lld\n",k);
	return 0;
}

