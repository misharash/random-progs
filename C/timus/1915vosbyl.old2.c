#include <stdio.h>
#include <string.h>
int main() {
	int n,i;
	scanf("%d",&n);
	int s[2*n],k=0,x;
	for (i=n;i>0;i--) {
		scanf("%d",&x);
		switch (x) {
			case -1: {
				k--;
				printf("%d\n",s[k]);
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
				s[k]=x;
				k++;
				break;
			}
		}
	}
	return 0;
}
