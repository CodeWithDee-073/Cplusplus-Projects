// Pandom Password generator project
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to generate the password based on selected complexity
string genPass(int len, bool up, bool low, bool dig, bool schar)
{
  string chars = "";

  // Adding character sets based on user selection
  if (up)
    chars += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  if (low)
    chars += "abcdefghijklmnopqrstuvwxyz";
  if (dig)
    chars += "0123456789";
  if (schar)
    chars += "@#$%^&*()_+-=[]{}|;:,.<>?";

  int size = chars.size(); // Get total number of characters available

  srand(time(0)); // Seed the random number generator for randomness

  string pass = "";
  for (int i = 0; i < len; i++)
  {
    int randomIndex = rand() % size; // Generate random index
    pass += chars[randomIndex];      // Append the character to the password
  }

  return pass;
}

int main()
{
  int len;
  bool up, low, dig, sc; // bool FOR YES(1) and NO(0)

  // Ask user for password length
  cout << "Enter password length: ";
  cin >> len;

  // Ask user about password complexity options
  cout << "Include Uppercase? (1 for yes, 0 for no): ";
  cin >> up;
  cout << "Include Lowercase? (1 for yes, 0 for no): ";
  cin >> low;
  cout << "Include Digits? (1 for yes, 0 for no): ";
  cin >> dig;
  cout << "Include Special Characters? (1 for yes, 0 for no): ";
  cin >> sc;

  // Generate and display one password based on user preferences
  string pass = genPass(len, up, low, dig, sc);
  cout << "Generated Password: " << pass << endl;

  return 0;
}