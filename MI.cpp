#include <iostream>
using namespace std;

int main()
{
    const int MODULUS = 10;
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Additive inverses in Z" << n << " are: " << endl;
    for (int i = 1; i < n; i++)
    {
        int inverse = 0;
        for (int j = 1; j < MODULUS; j++)
        {
            if ((i * j) % MODULUS == 1)
            {
                inverse = j;
                break;
            }
        }
        if (inverse > 0 && inverse != i)
        {
            cout << i << " and " << inverse << endl;
        }
    }

    return 0;
}
