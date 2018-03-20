#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "functions.hpp"

using namespace std;
double maxArr(double *ptrArr, int size)
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

double maxGrade(string filename)
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
    double maxVal = maxArr(arr, sizeArr);
    inputFile.close();
    delete [] arr;
    return maxVal;
}

void displayCircle(Circle circ)
{
  
}
