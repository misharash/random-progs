#include <stdio.h>
#define lm 6
#define el 5
char* m="Sandro";
int ulcase(char c) {
    if ((c>='A')&&(c<='Z'))
        return 0;
    if ((c>='a')&&(c<='z'))
        return 1;
    return 2;
}
int main() {
    char s[1000];
    scanf("%s",s);
    int i,j,st=2*lm*el,cst;
    for (i=0;s[i+lm-1]!='\0';i++) {
        cst=0;
        for (j=0;j<lm;j++) {
            if (s[i+j]!=m[j]) {
                cst+=el;
                if ((ulcase(s[i+j])!=ulcase(m[j]))&&((int)s[i+j]-(int)m[j]!=32)&&((int)s[i+j]-(int)m[j]!=-32))
                    cst+=el;
            }
        }
        if (cst<st)
            st=cst;
    }
    printf("%d\n",st);
    return 0;
}