#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate power of a number (a^b)
int power(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

int main() {
    int p, g, a, b;

    // Take user input for p, g, a and b
    cout << "Enter a prime number (p): ";
    cin >> p;
    cout << "Enter a primitive root of " << p << " (g): ";
    cin >> g;
    cout << "Enter a secret number for Alice (a): ";
    cin >> a;
    cout << "Enter a secret number for Bob (b): ";
    cin >> b;

    // Calculate A and B
    int A = power(g, a, p);
    int B = power(g, b, p);

    // Calculate the secret key of Alice and Bob
    int Ka = power(B, a, p);
    int Kb = power(A, b, p);

    // Calculate r1 and r2
    int r1 = power(g, a, p);
    int r2 = power(g, b, p);

    // Display the secret keys, r1 and r2
    cout << "Secret key of Alice: " << Ka << endl;
    cout << "Secret key of Bob: " << Kb << endl;
    cout << "r1 = g^a mod p: " << r1 << endl;
    cout << "r2 = g^b mod p: " << r2 << endl;

    // Check if the secret keys are the same
    if (Ka == Kb) {
        cout << "The shared secret key is: " << Ka << endl;
    } else {
        cout << "Error: The shared secret keys are not the same." << endl;
    }

    return 0;
}
