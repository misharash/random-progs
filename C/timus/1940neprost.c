#include <stdio.h>
#include <stdbool.h>
unsigned a,b,apb;
int p[100],kp=1;
int kpch(unsigned pr,int k,int g) {
	int i,r=(a+b)/pr-a/pr,gg=g+1;
	//if (g==0)
	//	g=1;
	//printf("%lld %lld %lld %lld\n",pr,k,g,r);
	for (i=k;i<kp;i++)
		if (pr<=apb/p[i])
			r-=kpch(pr*p[i],i+1,gg);
		else
			break;
	//printf("%lld %lld %lld %lld\n",pr,k,g,r);
	return r;
}
int main() {
	int k;
	scanf("%lld%lld%lld",&a,&b,&k);
	apb=a+b;
	int i,j,r=0;
	bool ip;
	p[0]=2;
	for (i=3;i<k+2;i++) {
		ip=true;
		for (j=0;j<kp;j++)
			if (!(i%p[j])) {
				ip=false;
				break;
			}
		if (ip) {
			p[kp]=i;
			kp++;
			if ((i>a)&&(i<=apb))
				r++;
		}
	}
	r+=kpch(1,0,0);
	printf("%d\n",r);
	return 0;
}