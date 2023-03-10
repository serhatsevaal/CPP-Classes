#ifndef british_currency_hpp
#define british_currency_hpp

#include <stdio.h>
#include <iostream>
#endif /* british_currency_hpp */

class british_currency{
private:
    
    int pounds = 0; //Default behaviour thanks to C++11, we don't have to have default constructor thanks to that
    int shillings = 0;
    int pences = 0;
    
public:
    
    british_currency(); //constructor, no return type, it's automatically auto-generated by the compiler it's not something that creates object!!, it's not generated if you create another constructor!!
    
    british_currency(int _pounds, int _shillings, int _pences); //I can add default values here to bypass default constructor, eğer değer verirsen burada default contstructor ile karışacağından hata verir
    
    int get_pounds() const;
    int get_shillings() const;
    int get_pences () const;
    
    void set_pounds(int _pounds);
    void set_shillings(int _shillings);
    void set_pences(int _pences);
    
    void fix();
    void read();
    void print() const;
    
};

british_currency add(const british_currency& bc1, const british_currency& bc2);
