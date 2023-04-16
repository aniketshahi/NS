#include <iostream>
#include <string>

using namespace std;

string encryptVigenere(string plaintext, string key)
{
    string ciphertext = "";
    int keyLength = key.length();
    int j = 0;
    for (int i = 0; i < plaintext.length(); ++i)
    {
        char currChar = plaintext[i];
        if (isalpha(currChar))
        {
            char keyChar = key[j % keyLength];
            keyChar = toupper(keyChar);
            int shift = keyChar - 'A';
            if (islower(currChar))
            {
                currChar = 'a' + (currChar - 'a' + shift) % 26;
            }
            else
            {
                currChar = 'A' + (currChar - 'A' + shift) % 26;
            }
            j++;
        }
        ciphertext += currChar;
    }
    return ciphertext;
}

string decryptVigenere(string ciphertext, string key)
{
    string plaintext = "";
    int keyLength = key.length();
    int j = 0;
    for (int i = 0; i < ciphertext.length(); ++i)
    {
        char currChar = ciphertext[i];
        if (isalpha(currChar))
        {
            char keyChar = key[j % keyLength];
            keyChar = toupper(keyChar);
            int shift = keyChar - 'A';
            if (islower(currChar))
            {
                currChar = 'a' + (currChar - 'a' - shift + 26) % 26;
            }
            else
            {
                currChar = 'A' + (currChar - 'A' - shift + 26) % 26;
            }
            j++;
        }
        plaintext += currChar;
    }
    return plaintext;
}

int main()
{
    string plaintext;
    string key;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter key: ";
    getline(cin, key);

    string ciphertext = encryptVigenere(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = decryptVigenere(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
