#include <stdio.h>
#include <stdbool.h>
int main() {
	int n,i,k,v[2][50000],vc[2]={0,0},nn;
	char s[100001];
	bool e[26],ee[26];
	gets(s);
	scanf("%d",&k);
	for (i=0;i<26;i++) {
		ee[i]=e[i]=false;
	for (n=0;s[n]!='\0';n++)
		if (s[n]=='?') {
			nn=n%2;
			v[nn][vc[nn]]=n;
			vc[nn]++;
		}
		else
			e[s[n]-97]=true;
}
