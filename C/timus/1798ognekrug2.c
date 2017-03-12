#include <stdio.h>
#define D 1
long long sqr(int a) {
	return (long long)a*a;
}
long long iabs(long long a) {
	if (a<0)
		return -a;
	return a;
}
int isqrt(long long a) {
	long long x=(a+1)/2,px,d;
	do {
		px=x;
		x=(x+a/x)/2;
		//printf("%lld",x);
		d=x-px;
	} while ((d>D)||(d<-D));
	while (sqr(x-1)>=a)
		x--;
	while (sqr(x)<a)
		x++;
	return x;
}
int cat(int a, int b) {
	return isqrt(sqr(a)-sqr(b));
}
int cat2(long long a) {
	return isqrt(a/2+a%2);
}
long long xint(int a, int b) {
	return (long long)a*b;
}
int main() {
	int r,l=0,lp=0,i,rr;
	long long k=0,r2;
	scanf("%d",&r);
	r2=sqr(r);
	rr=cat2(r2);
	for (i=r-1;i>=rr;i--) {
		lp=l;
		l=cat(r,i);
		//printf("%d\n",l);
		k+=xint(l-lp,2*i+2-l-lp);
		//printf("%lld\n",xint(l-lp,2*i+2-l-lp));
	}
	lp=l;
	l=rr;
	//printf("%d\n",l);
	k+=xint(l-lp,2*i+2-l-lp);
	//printf("%lld\n",xint(l-lp,2*i+2-l-lp));
	//printf("%lld\n",k);
	k*=4;
	printf("%lld\n",k);
	return 0;
}

