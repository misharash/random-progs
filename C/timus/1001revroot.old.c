#include <stdio.h>
#include <math.h>
#include <string.h>
int main() {
    long long t;
    char s[20000000]="",ss[20000000];
    while (scanf("%Ld",&t)!=EOF) {
        strcpy(ss,s);
        sprintf(s,"%0.4lf\n%s",sqrt(t),ss);
    }
    printf("%s",s);
    return 0;
}
