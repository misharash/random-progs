#include <stdio.h>
#include <string.h>
int main() {
	int n,i;
	scanf("%d",&n);
	int s[2*n],k=0,x[n];
	for (i=0;i<n;i++)
		scanf("%d",&x[i]);
	for (i=0;i<n;i++) {
		switch (x[i]) {
			case -1: {
				k--;
				printf("%d\n",s[k]);
				break;
			}
			case 0: {
				if (2*k<=n) {
					if (k>0)
						memcpy(&s[k],s,k*sizeof(int));
					k*=2;
				}
				else {
					if (k<n) {
						memmove(&s[n-k],s,k*sizeof(int));
						memcpy(s,&s[n-k],(n-k)*sizeof(int));
					}
					if (k>n)
						memmove(s,&s[k-n],n*sizeof(int));
					k=n;
				}
				break;
			}
			default: {
				s[k]=x[i];
				k++;
				break;
			}
		}
	}
	return 0;
}
