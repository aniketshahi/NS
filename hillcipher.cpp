#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// function to convert plain text to matrix
void textToMatrix(string plaintext, int matrix[][3], int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (k < plaintext.length())
                matrix[i][j] = (int)plaintext[k++] - 97;
            else
                matrix[i][j] = 23;
        }
    }
}

// function to convert matrix to cipher text
void matrixToText(int matrix[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << (char)(matrix[i][j] + 97);
        }
    }
}

// function to multiply two matrices
void multiplyMatrix(int a[][3], int b[][3], int result[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= 26;
        }
    }
}

// function to calculate inverse of a matrix
void inverse(int a[][3], int inverse[][3])
{
    int det = 0, adj[3][3];
    for (int i = 0; i < 3; i++)
    {
        det += (a[0][i] * (a[1][(i + 1) % 3] * a[2][(i + 2) % 3] - a[1][(i + 2) % 3] * a[2][(i + 1) % 3]));
    }

    if (det == 0)
    {
        cout << "Inverse does not exist";
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            adj[i][j] = (a[(j + 1) % 3][(i + 1) % 3] * a[(j + 2) % 3][(i + 2) % 3]) - (a[(j + 1) % 3][(i + 2) % 3] * a[(j + 2) % 3][(i + 1) % 3]);
            if ((i + j) % 2 == 1)
            {
                adj[i][j] = -adj[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inverse[i][j] = adj[i][j] / det;
            if (inverse[i][j] < 0)
            {
                inverse[i][j] += 26;
            }
        }
    }
}

int main()
{
    int key[3][3], inverse_key[3][3], plaintext_matrix[3][3], cipher_matrix[3][3];
    string plaintext;
    cout << "Enter plaintext (in lowercase): ";
    getline(cin, plaintext);
    cout << "Enter key matrix: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> key[i][j];
        }
    }

    // check if determinant is zero
  
    {
        cout << "Determinant is zero. Key is not valid.";
        return 0;
    }

    // calculate inverse key
    inverse(key, inverse_key);

    // pad plaintext if necessary
    int size = ceil((float)plaintext.length() / 3);
    textToMatrix(plaintext, plaintext_matrix, size);

    // multiply key with plaintext matrix
    multiplyMatrix(key, plaintext_matrix, cipher_matrix);

    // convert cipher matrix to ciphertext
    cout << "Cipher Text: ";
    matrixToText(cipher_matrix, size);

    // multiply inverse key with cipher matrix to get plaintext matrix
    multiplyMatrix(inverse_key, cipher_matrix, plaintext_matrix);

    // convert plaintext matrix to plaintext
    cout << "\nDecrypted Text: ";
    matrixToText(plaintext_matrix, size);

    return 0;
}