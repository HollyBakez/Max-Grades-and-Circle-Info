/*
MIT License

Copyright (c) 2018 Paul Salvador Inventado

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "catch.hpp"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "functions.hpp"

#include <random>

using namespace std;

string couttest(string progName, string input)
{
  FILE *fp = popen(("echo \""+ input +"\" | ./" + progName).c_str(), "r");
  char buf[1024];
  string output = "";
  while (fgets(buf, 1024, fp)) {
    output += buf;
  }
  pclose(fp);  
  return output;
}

string to_string_double(double val, const int prec = 2)
{
    std::ostringstream out;
    out << fixed << setprecision(prec) << val;
    return out.str();
}

string func_str_out(function<void()> func)
{
  // code for capturing cout taken from
  // https://stackoverflow.com/questions/19485536/redirect-output-of-an-function-printing-to-console-to-string
  std::stringstream ss;
  auto old_buf = std::cout.rdbuf(ss.rdbuf()); 
  func();
  std::cout.rdbuf(old_buf);
  return ss.str();
}

TEST_CASE("Maximum grade", "[maxgrade]")
{
  srand(time(NULL));
  SECTION("Maxgrade")
  {
    for(int j = 0; j < 10; j++)
      {
      ofstream outputFile("maxgrade.txt");
      if(outputFile){
        outputFile.close();
        remove("maxgrade.txt");
      }
      outputFile.open("maxgrade.txt");
      int size = rand() % 10 + 1;
      outputFile << size << endl;
      double max = -1;
      for(int i = 0; i < size; i++)
      {
        double num = (double)rand() / RAND_MAX * 100;
        if(i == 0 || max < num)
          max = num;
        outputFile << num << endl;
      }
      outputFile.close();
      CHECK_THAT(maxGrade("maxgrade.txt"), Catch::WithinAbs(max, .01));
      //CHECK(maxGrade("maxgrade.txt") == max);
    }
  }
}

TEST_CASE("Display circle", "[circle]")
{
  srand(time(NULL));
  SECTION("Display")
  {
    for(int i = 0; i < 10; i++)
    {
      Circle c;
      double rad = (double)rand() / RAND_MAX * 100;
      c.setRadius(rad);
      string expected = "Circle information\n";
      expected += "Radius: " + to_string_double(rad) + "\n";
      expected += "Circumference: " + to_string_double(c.getCircumference()) + "\n";
      expected += "Area: " + to_string_double(c.getArea());
      string output = func_str_out([&](){
        displayCircle(c);
      });
      CHECK(output == expected);
    }
  }
}