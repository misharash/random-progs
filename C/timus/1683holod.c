#include <stdio.h>
int uplog2(int a) {
	int p=1,i=0;
	while (a>p) {
		p*=2;
		i++;
	}
	return i;
}
int main() {
    
}
