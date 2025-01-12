#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string genPass(int len, bool up, bool low, bool dig, bool schar)
{
  string chars = " ";

  if (up)
    chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  if (low)
    chars += "abcdefghijklmnopqrstuvwxyz";
  if (dig)
    chars += "0123456789";
  if (schar)
    chars += "@#$%^&*()_+-=[]{}|;:,.<>?";

  int size = chars.size(); 

  srand(time(0)); 

  string pass = "";
  for (int i = 0; i < len; i++)
  {
    int randomIndex = rand() % size; 
    pass += chars[randomIndex];      
  }

  return pass;
}

int main()
{
  int l;
  bool up, low, dig, sc; 

  // Ask user for password length
  cout << "Enter password length: ";
  cin >> l;

  // Ask user about password  options
  cout << "Include Uppercase? (1 for yes, 0 for no): ";
  cin >> up;
  cout << "Include Lowercase? (1 for yes, 0 for no): ";
  cin >> low;
  cout << "Include Digits? (1 for yes, 0 for no): ";
  cin >> dig;
  cout << "Include Special Characters? (1 for yes, 0 for no): ";
  cin >> sc;

  string pass = genPass(l, up, low, dig, sc);
  cout << "Generated Password: " << pass << endl;

  return 0;
}