#include <iostream>
using namespace std;
string additiveCipher(string message, int key)
{
    string ciphertext = "";
    for (int i = 0; i < message.length(); i++)
    {  if(int(message[i]) >= 65 && int(message[i] <=90 )){
        char currentchar = message[i];
        char encryptedchar = ((8*(currentchar - 'A' + key) % 26) )+ 'A';
        ciphertext += encryptedchar;
    }
       else{
            ciphertext += message[i];
        }
    }
    return ciphertext;
}
int main()
{
    string message;
    int key;
    cout << "Enter message: ";
    getline(cin, message);
    cout << "Enter key: ";
    cin >> key;
    string ciphertext = additiveCipher(message, key);
    cout << "ciphertext: " << ciphertext << endl;
    return 0;
}