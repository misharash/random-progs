#include <stdio.h>
#include <cmath>
#include <string>
using namespace std;
int main() {
    long long t;
    string s,ss;
    while (scanf("%Ld",&t)!=EOF) {
        sprintf(ss,"%0.4lf\n",sqrt(t));
        s=ss+s;
    }
    printf("%s",s);
    return 0;
}
