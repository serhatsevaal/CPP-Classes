#include <iostream>
#include "british_currency.hpp"
using namespace std;



void lecture1() {
    
    british_currency bc ;
    bc.read();
    bc.print();
    
    british_currency bc2(2, 4 ,6);
    
    bc = add(bc,bc2);
    bc.print();
    
}
