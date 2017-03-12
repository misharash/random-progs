#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
	int n[10],i,j;
	char k=1,p;
	div_t d;
	bool r=true;
	for (i=0;i<10;i++)
		scanf("%d",&n[i]);
	for (i=2;r;i++) {
		r=false;
		p=1;
		for (j=0;j<10;j++) {
			while (!(d=div(n[j],i)).rem) {
				p++;
				if (p==10)
					p=0;
				n[j]=d.quot;
			}
			if (n[j]>1)
				r=true;
		}
		k=k*p%10;
		if (!k)
			break;
	}
	printf("%d\n",k);
	return 0;
}

