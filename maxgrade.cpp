#include <iostream>
#include "functions.hpp"

using namespace std;

int main()
{
  string filename = "grades.txt";
  cout << "The maximum grade in " << filename << " is " << maxGrade(filename);
  return 0;
}
