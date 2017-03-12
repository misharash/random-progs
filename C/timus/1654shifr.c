#include <stdio.h>
int main() {
	char s[200010],ss[200010];
	int i,pi=1;
	gets(s);
	ss[0]='\0';
	ss[1]=s[0];
	for (i=1;s[i]!='\0';i++) {
		if (s[i]==ss[pi])
			pi--;
		else {
			pi++;
			ss[pi]=s[i];
		}
	}
	ss[pi+1]='\0';
	printf("%s\n",&ss[1]);
	return 0;
}
