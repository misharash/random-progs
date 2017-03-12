#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    if ((n/2+n%2)%2)
        printf("grimy\n");
    else
        printf("black\n");
    return 0;
}