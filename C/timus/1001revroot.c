#include <stdio.h>
#include <math.h>
int main() {
    double t[256000];
    int k;
    for (k=0;scanf("%lf",&t[k])!=EOF;k++);
    int i;
    for (i=k-1;i>=0;i--)
        printf("%0.4lf\n",sqrt(t[i]));
    return 0;
}
