#include <stdio.h>
int main() {
	int i,p=0;
	char scr[81],in[10001];
	for (i=0;i<80;i++)
		scr[i]=' ';
	scr[80]='\0';
	gets(in);
	for (i=0;in[i]!='\0';i++) {
		switch (in[i]) {
			case '<': {
				p--;
				break;
			}
			case '>': {
				p++;
				break;
			}
			default: {
				scr[p]=in[i];
				p++;
				break;
			}
		}
		if ((p<0)||(p>=80))
			p=0;
		//printf("%d %c %d %s\n",i,in[i],p,scr);
	}
	printf("%s\n",scr);
	return 0;
}
