#include <stdio.h>
#include <string.h>
int main() {
	int n,i;
	scanf("%d",&n);
	int s[2*n],k=0,x[n],p=0,o[n],kb=n+1,ke=n+1;
	for (i=0;i<n;i++)
		scanf("%d",&x[i]);
	for (i=n;i>0;i--) {
		switch (x[n-i]) {
			case -1: {
				k--;
				o[p]=s[kb];
				kb++;
				p++;
				break;
			}
			case 0: {
				if (2*k<=i) {
					memcpy(&s[ke],&s[kb],k*sizeof(int));
					ke+=k;
					k*=2;
				}
				else
					if (k<i) {
						memcpy(&s[ke],&s[kb],(i-k)*sizeof(int));
						k=i;
						ke=kb+k;
					}
				break;
			}
			default: {
				kb--;
				s[kb]=x[n-i];
				k++;
				break;
			}
		}
	}
	for (i=0;i<p;i++)
		printf("%d\n",o[i]);
	return 0;
}
