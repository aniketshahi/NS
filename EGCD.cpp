#include <iostream>
using namespace std;

int extendedGCD(int a, int b, int& s, int& t) {
    if (b == 0) {
        s = 1;
        t = 0;
        return a;
    }
    int s1, t1;
    int gcd = extendedGCD(b, a % b, s1, t1);
    s = t1;
    t = s1 - (a / b) * t1;
    return gcd;
}

int main() {
    int a, b, s, t;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int gcd = extendedGCD(a, b, s, t);
    cout << "GCD of " << a << " and " << b << " is " << gcd << endl;
    cout << "s = " << s << ", t = " << t << endl;
    return 0;
}