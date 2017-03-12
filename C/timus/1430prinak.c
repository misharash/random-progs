#include <stdio.h>
int main() {
	unsigned a,b,n,ka,kb,i;
	scanf("%u%u%u",&a,&b,&n);
	if (a>=b) {
		if ((long long)a*(long long)a>(long long)n) {
			unsigned k=n/a,o=n,oo;
			//printf("%u\n",k);
			for (i=0;i<=k;i++) {
				if ((oo=(n-i*a)%b)<=o) {
					o=oo;
					ka=i;
					kb=(n-i*a)/b;
					//printf("%u %u\n",ka,kb);
				}
				//printf("%u %u\n",i,oo);
			}
		}
		else {
			unsigned aa=a%b,o=n,oo;
			for (i=0;i<b;i++) {
				if ((oo=(n-aa*i)%b)<=o) {
					o=oo;
					ka=i;
					kb=(n-a*i)/b;
				}
			}
		}
	}
	else {
		if ((long long)b*(long long)b>(long long)n) {
			unsigned k=n/b,o=n,oo;
			//printf("%u\n",k);
			for (i=0;i<=k;i++) {
				if ((oo=(n-i*b)%a)<=o) {
					o=oo;
					ka=(n-i*b)/a;
					kb=i;
					//printf("%u %u\n",ka,kb);
				}
				//printf("%u %u\n",i,oo);
			}
		}
		else {
			unsigned bb=b%a,o=n,oo;
			for (i=0;i<a;i++) {
				if ((oo=(n-bb*i)%a)<=o) {
					o=oo;
					ka=(n-b*i)/a;
					kb=i;
				}
			}
		}
	}
	printf("%u %u\n",ka,kb);
	return 0;
}
