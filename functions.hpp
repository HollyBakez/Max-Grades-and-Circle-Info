#include <string>
using namespace std;

class Circle {
  private:
    double radius;
    const double PI = 3.14;
  public:
    void setRadius(double rad)
    {
      radius = rad;
    }
    double getRadius()
    {
      return radius;
    }

   double getArea()
   {
     return PI * radius * radius;
   }

   double getCircumference()
   {
     return 2 * PI * radius;
   }
};

double maxArr(double *ptrArr, int size);
double maxGrade(string filename);
void displayCircle(Circle circ);

