#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter the value of zn:";
    int n;
    cin>>n;
    int zn[n];
    for(int k=0;k<n;k++){
        zn[k]=k;
    }
    

    cout << "Additive inverses in Zn are: " << endl;
    for (int i = 0; i < (n / 2) + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((zn[i] + j) % 10 == 0)
            {
                cout << zn[i] << " and " << j << endl;
            }
        }
    }
    

    return 0;
}
