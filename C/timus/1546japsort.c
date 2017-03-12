#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool isdig(char c) {
	return (c>='0')&&(c<='9');
}
bool islet(char c) {
	return (c>='a')&&(c<='z');
}
char* strend(char* s) {
	while (*(s++));
	return s;
}
int jastrcmp(const void* a1,const void* a2) {
	char *s1,*s2,*ss1,*ss2;
	s1=*((char**)a1);
	s2=*((char**)a2);
	ss1=s1;
	ss2=s2;
	int r=0;
	while ((!r)&&(*s1)&&(*s2)) {
		while ((!r)&&islet(*s1)&&islet(*s2))
			r=*(s1++)-*(s2++);
		if (!r) {
			if (!((!islet(*s1))&&(!islet(*s2))))
				r=*s1-*s2;
			else {
				if (!*s1)
					r=-150;
				if (!*s2)
					r=150;
				if ((!*s1)&&(!*s2))
					r=0;
				while (*s1=='0')
					s1++;
				while (*s2=='0')
					s2++;
				while (isdig(*s1)&&isdig(*s2)) {
					if (!r)
						r=*s1-*s2;
					s1++;
					s2++;
				}
				if (!((!isdig(*s1))&&(!isdig(*s2)))) {
					if (isdig(*s1))
						r=100;
					else
						r=-100;
				}
			}
		}
	}
	if (!r) {
		if (!*s1)
			r=-200;
		if (!*s2)
			r=200;
		if ((!*s1)&&(!*s2))
			r=0;
	}
	//printf("%s %s %d\n",ss1,ss2,r);
	if (r)
		return r;
	s1=ss1;
	s2=ss2;
	while ((!r)&&(*s1)&&(*s2))
		r=*(s1++)-*(s2++);
	if (!r) {
		if (!*s1)
			r=300;
		if (!*s2)
			r=-300;
		if ((!*s1)&&(!*s2))
			r=0;
	}
	//printf("%s %s %d\n",ss1,ss2,r);
	return r;
}
int main() {
	char s[110000],*st[110000],*str;
	str=&s;
	int i,n;
	for (n=0;gets(str);n++) {
		st[n]=str;
		str=strend(str);
	}
	qsort(st,n,sizeof(char*),jastrcmp);
	for (i=0;i<n;i++)
		printf("%s\n",st[i]);
	return 0;
}
