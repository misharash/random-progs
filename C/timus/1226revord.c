#include <stdio.h>
int main() {
    char s[20000],b;
    int i,nl=1,fl,ll,l2,j;
    while (gets(s)) {
        i=-1;
        fl=0;
        ll=0;
        do {
            i++;
            if (((s[i]>='a')&&(s[i]<='z'))||((s[i]>='A')&&(s[i]<='Z'))) {
                if (nl) {
                    nl=0;
                    fl=i;
                }
            }
            else {
                nl=1;
                ll=i-1;
                l2=(i-fl)/2;
                for (j=0;j<l2;j++) {
                    b=s[fl+j];
                    s[fl+j]=s[ll-j];
                    s[ll-j]=b;
                }
                fl=i;
            }
        } while (s[i]!='\0');
        printf("%s\n",s);
    }
    return 0;
}