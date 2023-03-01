#include <iostream>
#include "CMPLX.hpp"
#define SIZE 3
using namespace std;



void lab1() {
    // insert code here...
    CMPLX x,y,z;
    CMPLX tab_x[] = {{3,4},{1,3},{5,-2}};
    CMPLX tab_y[] = {{3,4},{1,3},{5,-2}};
    CMPLX tab_z[SIZE];
    double result;
    int i;
    
    
    cout << "Enter first complex number (C1): ";
    x.ReadC();
    cout << "Enter first complex number (C2): ";
    y.ReadC();
    
    
    cout << "Your first complex number is (C1): ";
    x.PrintC();
    cout << "\nYour first complex number is (C2): ";
    y.PrintC();
    
    
    //z = Add(x,y);
    z = x+y;
    cout << "\nSum of C1 + C2: ";
    z.PrintC();
    
    
    result = z.AbsC();
    cout << "\nAbs of C1 + C2: " << result << "\n";
    
    
    cout << "First array of complex numbers is (A1): ";
    PrintArray(tab_x, SIZE);
    
    
    cout << "\nFirst array of complex numbers is (A2): ";
    PrintArray(tab_y, SIZE);

    
    Add(tab_x, tab_y, tab_z, SIZE);
    cout << "\nSum of A1 + A2: ";
    for (i = 0; i < SIZE; i++)
        tab_z[i].PrintC();
    
    
    cout << "\nand Abs(A1 + A2): ";
    for (i = 0; i < SIZE; i++)
        cout << tab_z[i].AbsC() << " ";
    
    
    SortArray(tab_z, SIZE);
    cout << "\nSorted array (by abs): ";
    PrintArray(tab_z, SIZE);
    
    
    cout << "\nand abs values: ";
    for (i = 0; i < SIZE; i++)
        cout << tab_z[i].AbsC() << " ";
}
    
