#include <iostream>
using namespace std;
long long b1(long long a) {
    if (a>1)
        return a;
    return 0;
}
int main() {
    long long n,pa,pe;
    cin >> n;
    if (n%2) {
        pe=0;
        pa=b1(n/2-1)*n;
    }
    else {
        pa=(b1(n/2-1)+b1(n/2-2))*n/2;
        pe=(n-3)*n/2;
    }
    cout << pa << ' ' << pe << endl;
    return 0;
}