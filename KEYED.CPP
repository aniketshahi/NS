#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to encrypt the plaintext using Keyed Transposition Cipher
std::string encrypt(const std::string& plaintext, const std::string& key) {
    std::string ciphertext = "";
    int keyLength = key.length();

    // Create a vector of pairs to store the characters and their corresponding positions in the key
    std::vector<std::pair<char, int>> keyPositions;

    // Store the characters and their corresponding positions in the key in the vector
    for (int i = 0; i < keyLength; i++) {
        keyPositions.push_back(std::make_pair(key[i], i));
    }

    // Sort the vector based on the characters in ascending order
    std::sort(keyPositions.begin(), keyPositions.end());

    int plaintextLength = plaintext.length();

    // Calculate the number of columns in the transposition table
    int numColumns = (plaintextLength + keyLength - 1) / keyLength;

    // Create a 2D vector to represent the transposition table
    std::vector<std::vector<char>> transpositionTable(numColumns, std::vector<char>(keyLength, ' '));

    // Fill the transposition table with the characters from the plaintext
    int pos = 0;
    for (int i = 0; i < keyLength; i++) {
        for (int j = 0; j < numColumns; j++) {
            if (pos < plaintextLength) {
                transpositionTable[j][keyPositions[i].second] = plaintext[pos++];
            }
        }
    }

    // Read the ciphertext from the transposition table column-wise
    for (int i = 0; i < numColumns; i++) {
        for (int j = 0; j < keyLength; j++) {
            ciphertext += transpositionTable[i][j];
        }
    }

    return ciphertext;
}

// Function to decrypt the ciphertext using Keyed Transposition Cipher
std::string decrypt(const std::string& ciphertext, const std::string& key) {
    std::string plaintext = "";
    int keyLength = key.length();

    // Calculate the number of columns in the transposition table
    int numColumns = (ciphertext.length() + keyLength - 1) / keyLength;

    // Create a 2D vector to represent the transposition table
    std::vector<std::vector<char>> transpositionTable(numColumns, std::vector<char>(keyLength, ' '));

    // Fill the transposition table with the characters from the ciphertext
    int pos = 0;
    for (int i = 0; i < numColumns; i++) {
        for (int j = 0; j < keyLength; j++) {
            if (pos < ciphertext.length()) {
                transpositionTable[i][j] = ciphertext[pos++];
            }
        }
    }

    // Create a vector of pairs to store the characters and their corresponding positions in the key
    std::vector<std::pair<char, int>> keyPositions;

    // Store the characters and their corresponding positions in the key in the vector
    for (int i = 0; i < keyLength; i++) {
        keyPositions.push_back(std::make_pair(key[i], i));
    }

    // Sort the vector based on the characters in ascending order
    std::sort(keyPositions.begin(), keyPositions.end());

    // Read the plaintext from the transposition table row-wise
    for (int i = 
0; i < numColumns; i++) {
for (int j = 0; j < keyLength; j++) {
plaintext += transpositionTable[i][keyPositions[j].second];
}
}


return plaintext;
}

int main() {
// Get user input for plaintext and key
std::string plaintext, key;
std::cout << "Enter the plaintext: ";
std::getline(std::cin, plaintext);
std::cout << "Enter the key: ";
std::getline(std::cin, key);


// Encrypt the plaintext using the key
std::string ciphertext = encrypt(plaintext, key);
std::cout << "Ciphertext: " << ciphertext << std::endl;

// Decrypt the ciphertext using the key

return 0;
}
