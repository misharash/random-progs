#include <stdio.h>
int main() {
    char s[20000];
    int np=1,i;
    while (gets(s)) {
        for (i=0;s[i]!='\0';i++)
            if ((s[i]>='A')&&(s[i]<='Z'))
                if (np)
                    np=0;
                else
                    s[i]+=32;
            else
                if ((s[i]=='.')||(s[i]=='!')||(s[i]=='?'))
                    np=1;
        printf("%s\n",s);
    }
    return 0;
}