#include <stdio.h>
#include <string.h>
int main() {
	int n,i;
	scanf("%d",&n);
	int s[2*n],k=0,x[n],p=0,o[n];
	for (i=0;i<n;i++)
		scanf("%d",&x[i]);
	for (i=n;i>0;i--) {
		switch (x[n-i]) {
			case -1: {
				k--;
				o[p]=s[k];
				p++;
				break;
			}
			case 0: {
				if (2*k<=i) {
					memcpy(&s[k],s,k*sizeof(int));
					k*=2;
				}
				else {
					if (k<i) {
						memmove(&s[i-k],s,k*sizeof(int));
						memcpy(s,&s[k],(i-k)*sizeof(int));
					}
					if (k>i)
						memmove(s,&s[k-i],i*sizeof(int));
					k=i;
				}
				break;
			}
			default: {
				s[k]=x[n-i];
				k++;
				break;
			}
		}
	}
	for (i=0;i<p;i++)
		printf("%d\n",o[i]);
	return 0;
}
