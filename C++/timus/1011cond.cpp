#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double pp,qq;
    cin >> pp >> qq;
    int p=rint(100*pp),q=rint(100*qq);
//     cout << p << endl << q << endl;
    bool f=true;
    long c=1,pk,qk,qo;
    while (f) {
        c++;
        pk=(p*c)/10000;
        qk=(q*c)/10000;
        if (qk>pk) {
            f=false;
            qo=(q*c)%10000;
            if ((qk==pk+1)&&(qo==0))
                f=true;
        }
    }
    cout << c << endl;
}