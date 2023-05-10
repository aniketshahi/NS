#include <iostream>
#include <string>

using namespace std;

string additiveCipher(string plaintext, int key) {
    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++) {
        char currentChar = plaintext[i];
        char encryptedChar = ((currentChar - 'a' + key) % 26) + 'a';
        ciphertext += encryptedChar;
    }

    return ciphertext;
}

int main() {
    string plaintext;
    int key;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter key: ";
    cin >> key;

    string ciphertext = additiveCipher(plaintext, key);

    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}