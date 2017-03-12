#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int i;
    long long k,t;
    for (i=0;i<n-1;i++) {
        cin >> k;
        k--;
        t=llrint(sqrtl(2*(long double)k));
        if ((t*(t+1)/2==k)||(t*(t-1)/2==k))
            cout << "1 ";
        else
            cout << "0 ";
    }
    cin >> k;
    k--;
    t=llrint(sqrtl(2*(long double)k));
    if ((t*(t+1)/2==k)||(t*(t-1)/2==k))
        cout << "1";
    else
        cout << "0";
    return 0;
}