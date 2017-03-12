#include <stdio.h>
int main() {
    char s[2010];
    int i=0,k=0,c=0;
    scanf("%s",s);
    while (s[i]!='\0') {
        c=((int) s[i])-48;
        if (c%5==4)
            c=2;
        else
            c=c%5+c/5;
        k+=c;
        i++;
    }
    printf("%d\n",k);
    return 0;
}