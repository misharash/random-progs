#include <stdio.h>
int main() {
	char s[200010],ss[200010];
	int i,pi=0;
	gets(&s[1]);
	s[0]=' ';
	for (i=1;s[i]!='\0';i++) {
		if (s[i]==s[pi]) {
			s[i]='.';
			s[pi]='.';
			pi--;
		}
		else
			pi=i;
		for (;s[pi]=='.';pi--);
	}
	pi=0;
	for (i=1;s[i]!='\0';i++)
		if (s[i]!='.') {
			ss[pi]=s[i];
			pi++;
		}
	ss[pi]='\0';
	printf("%s\n",ss);
	return 0;
}
