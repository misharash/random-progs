#include <stdio.h>
int main() {
	int n,i,k=1,a,b,c;
	scanf("%d",&n);
	for (i=2;2*i<n;i++) {
		a=n;
		b=i;
		while (b) {
			c=b;
			b=a%b;
			a=c;
		}
		if (a==1)
			k++;
	}
	printf("%d\n",k);
	return 0;
}
