#include <stdio.h>
#include <math.h>
int main() {
    char s[1100000];
    scanf("%s",s);
    double x=0,y=0,p=sqrt(2)/2;
    long i=0;
    int d=1;
    while ((s[i]!='\0')&&d) {
        switch (s[i]) {
            case '0': {
                d=0;
                break;
            }
            case '1': {
                x-=p;
                y-=p;
                break;
            }
            case '2': {
                y-=1;
                break;
            }
            case '3': {
                x+=p;
                y-=p;
                break;
            }
            case '4': {
                x-=1;
                break;
            }
            case '6': {
                x+=1;
                break;
            }
            case '7': {
                x-=p;
                y+=p;
                break;
            }
            case '8': {
                y+=1;
                break;
            }
            case '9': {
                x+=p;
                y+=p;
                break;
            }
        }
        i++;
    }
    printf("%0.10lf %0.10lf\n",x,y);
    return 0;
}