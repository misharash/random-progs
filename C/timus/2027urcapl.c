#include <stdio.h>
int main() {
	int h,w,i=0,j=0, fi=0,fj=1,ri=1,rj=0,c[26],cc=0, b,bb,rn,k,t,p;
	scanf("%d%d",&h,&w);
	char code[h][w+1];
	for (k=0;k<h;k++)
		scanf("%s",&code[k]);
	i=0;
	for (k=0;k<26;k++)
		c[k]=0;
	scanf("%d",&k);
	int in[k];
	for (p=0;p<k;p++)
		scanf("%d",&in[p]);
	p=0;
	for (t=0;t<1000000;t++) {
		switch(code[i][j]) {
			case '#': return 0;
			case '^': {
				fi=-1;
				fj=0;
				ri=0;
				rj=1;
				break;
			}
			case 'v': {
				fi=1;
				fj=0;
				ri=0;
				rj=-1;
				break;
			}
			case '>': {
				fi=0;
				fj=1;
				ri=1;
				rj=0;
				break;
			}
			case '<': {
				fi=0;
				fj=-1;
				ri=-1;
				rj=0;
				break;
			}
			case '?': {
				cc=in[p];
				if (p<k-1)
					p++;
				break;
			}
			case '!': {
				printf("%d\n",cc);
				cc=0;
				break;
			}
			case '@': {
				b=fi;
				bb=fj;
				if (cc) {
					fi=ri;
					fj=rj;
					ri=-b;
					rj=-bb;
				}
				else {
					fi=-ri;
					fj=-rj;
					ri=b;
					rj=bb;
				}
				break;
			}
			case '+': {
				cc++;
				break;
			}
			case '-': {
				cc--;
				break;
			}
			 default: {
				if ((code[i][j]>='A')&&(code[i][j]<='Z')) {
					rn=((int) code[i][j])-65;
					b=cc;
					cc=c[rn];
					c[rn]=b;
				}
				break;
			}
		}
		if ((cc>100000)||(cc<-100000)) {
			printf("OVERFLOW ERROR\n");
			return 0;
		}
		i+=fi;
		j+=fj;
		if ((i>=h)||(i<0)||(j>=w)||(i<0)) {
			printf("RUNTIME ERROR\n");
			return 0;
		}
	}
	printf("TIME LIMIT EXCEEDED\n");
	return 0;
}
