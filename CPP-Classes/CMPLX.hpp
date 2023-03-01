#pragma once
#ifndef CMPLX_hpp
#define CMPLX_hpp

#include <stdio.h>

struct CMPLX{
    double Re, Im;
    void ReadC();
    void PrintC();
    double AbsC();
};

CMPLX Add(CMPLX a, CMPLX b);
void Add(CMPLX* a, CMPLX* b, CMPLX* c, int size);
void PrintArray(CMPLX* a, const int size);
void SortArray(CMPLX* a, const int size);
CMPLX operator+(CMPLX a, CMPLX b);

#endif /* CMPLX_hpp */
