#include "CMPLX.hpp"
#include <iostream>
#include <math.h>

using namespace std;

inline double pow(double a){
    return a*a;
}

void CMPLX::ReadC(){
    cin >> this->Re >> this->Im;
}

void CMPLX::PrintC(){
    cout << this->Re << " + " << this->Im << "i ";
}

double CMPLX::AbsC(){
    return sqrt(pow(this->Im)+pow(this->Re));
}

CMPLX Add(CMPLX a, CMPLX b){
    a.Re+=b.Re;
    a.Im+=b.Im;
    return a;
}

void Add( CMPLX* a, CMPLX* b, CMPLX* c, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        c[i] = Add(a[i], b[i]);
    }
}

void PrintArray(CMPLX* a, const int size){
    for(int i = 0; i<size; i++)
        a[i].PrintC();
}

void SortArray(CMPLX* a, const int size){
    for(int i = 0; i < size; i++){
        for(int k = i+1; k < size; k++){
            if(a[i].AbsC()>a[k].AbsC()){
                CMPLX b = a[i];
                a[i] = a[k];
                a[k] = b;
            }
        }
    }
}

CMPLX operator+(CMPLX a, CMPLX b){
    a.Re+=b.Re;
    a.Im+=b.Im;
    return a;
}
