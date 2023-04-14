/*
  C++ code for modular multiplicative
  inverse using an efficient approach of
  Extended Euclid Algorithm
*/
#include <iostream>
using namespace std;

// Function for extended Euclidean Algorithm
int Find_gcd_Extended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
void Find_mod_Inverse(int a, int m)
{
  int x, y;
  int g = Find_gcd_Extended(a, m, &x, &y);

  /*
    If the gcd value doesn't matches
    to 1, then inverse doesn't exist
  */
  if (g != 1)
  {
    cout << "Inverse doesn't exist";
  }
  else
  {
    /*
      m is added once more to handle
      negative values
    */
    int res = (x % m + m) % m;
    cout << res << endl;
  }
}

// Function to find extended Euclidean Algorithm
int Find_gcd_Extended(int a, int b, int *x, int *y)
{

  // Base Case
  if (a == 0)
  {
    *x = 0, *y = 1;
    return b;
  }

  // Storing results of recursive call
  int x1, y1;
  int gcd = Find_gcd_Extended(b % a, a, &x1, &y1);

  /*
    After recursive call, update the values
    of x and y
  */
  *x = y1 - (b / a) * x1;
  *y = x1;

  return gcd;
}

// Driver Code
int main()
{
  int a = 5, m = 7;

  // Function call
  cout << "The value of x is: ";
  Find_mod_Inverse(a, m);
  return 0;
}