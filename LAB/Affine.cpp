#include <iostream>
#include <string>

using namespace std;

// Function to compute modular multiplicative inverse
int modInverse(int a, int m) {
    a = a % m;
    for(int x = 1; x < m; x++) {
        if((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// Function to decrypt Affine cipher
string decryptAffineCipher(string cipherText, int a, int b) {
    string plainText = "";
    int n = cipherText.length();
    int aInv = modInverse(a, 26); // compute modular multiplicative inverse of a
    for(int i = 0; i < n; i++) {
        char c = cipherText[i];
        if(isalpha(c)) {
            c = toupper(c);
            c = (aInv * (c - 'A' - b + 26)) % 26 + 'A'; // compute plain text character
        }
        plainText += c;
    }
    return plainText;
}

int main() {
    string cipherText;
    int a, b;
    cout << "Enter the cipher text: ";
    getline(cin, cipherText);
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    string plainText = decryptAffineCipher(cipherText, a, b);
    cout << "Plain text: " << plainText << endl;
    return 0;
}