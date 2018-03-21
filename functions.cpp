//Holland Ho
//Date:3/20/18
//This program has functions that calculates the max grade value from reading a file, and a function that displays the information of a circle
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "functions.hpp"

using namespace std;
double maxArr(double *ptrArr, int size) //This function finds the maximum value in an array
{
    double maxVal=0;
    for(int i=0; i < size; i++)
    {
        if(ptrArr[i]>maxVal)
        {
            maxVal=ptrArr[i];
        }
        
    }
    
    return maxVal;
}

double maxGrade(string filename) //This function reads values from a file and creates a new array and returns the maximum value from it
{
    
    ifstream inputFile;
    inputFile.open(filename);
    
    int sizeArr=0;
    
    inputFile >> sizeArr;
    double *arr=new double[sizeArr];
    double num;
    int i=0;
    while (inputFile >> num && i != sizeArr)
    {
        arr[i]=num;
        i++;
    }
    double maxVal = maxArr(arr, sizeArr); //Replaces with biggest number within the array as the maximum value
    inputFile.close();
    delete [] arr;
    return maxVal; //Returns the maximum value from the array
}

void displayCircle(Circle circ) //This function displays the information of a circle
{
    cout<< "Circle information"<< endl;
    cout<< fixed << setprecision(2);
    cout<< "Radius: "<< circ.getRadius() << endl;
    cout<< "Circumference: "<< circ.getCircumference() << endl;
    cout<< "Area: "<< circ.getArea();
}
