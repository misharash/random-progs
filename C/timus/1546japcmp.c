#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isdigit(char c) {
	return (c>='0')&&(c<='9');
}
bool isletter(char c) {
	return (c>='a')&&(c<='z');
}
int jastrcmp(const void* a1,const void* a2) {
	char *s1,*s2,*ss1,*ss2;
	s1=*((char**)a1);
	s2=*((char**)a2);
	ss1=s1;
	ss2=s2;
	int r=0;
	while ((!r)&&(*s1)&&(*s2)) {
		while ((!r)&&isletter(*s1)&&isletter(*s2))
			r=*(s1++)-*(s2++);
		if (!r) {
			if (!((!isletter(*s1))&&(!isletter(*s2))))
				r=*s1-*s2;
			else {
				while (*s1=='0')
					s1++;
				while (*s2=='0')
					s2++;
				while ((!r)&&isdigit(*s1)&&isdigit(*s2)) {
					if (!r)
						r=*s1-*s2;
					s1++;
					s2++;
				}
				if (!((!isdigit(*s1))&&(!isdigit(*s2)))) {
					if (isdigit(*s1))
						r=100;
					else
						r=-100;
				}
			}
		}
	}
	if (r)
		return r;
	return strcmp(ss1,ss2);
}
int main() {
	char s1[30],s2[30];
	gets(s1);
	gets(s2);
	char *ss1,*ss2;
	ss1=s1;
	ss2=s2;
	//printf("%d %d %d %d\n",s1,s2,&ss1,&ss2);
	printf("%d\n",jastrcmp(&ss1,&ss2));
	return 0;
}
