#include "british_currency.hpp"

british_currency::british_currency() : pounds(0), shillings(0), pences(0)  //Initilization list, allows initilize const variables// it does the same as commented lines
{
    /*pounds = 0;
    shillings = 0;
    pences = 0;*/
    
}

british_currency::british_currency(int pounds, int shillings, int pences) : pounds(pounds), shillings(shillings), pences(pences) // we can bypass this by using initilization list
{ //aynı isim olunca hata veriyor this ile sorunu çözebilirsin
    /*this->pounds = pounds;
    this->shillings = shillings;
    this->pences = pences;*/
    fix();
}

void british_currency::fix(){
    if(pences<0|| shillings<0|| pences<0){
        shillings = pences = pounds = 0;
    }
    shillings += pences/12;
    pences = pences %12;
    pounds += shillings/20;
    shillings = shillings%20;
}
void british_currency::read(){
    std::cout << "Enter pounds, shillings, and pences: ";
    std::cin >> this->pounds >> this->shillings >> this->pences;
    fix();
}
void british_currency::print() const{
    std::cout << pounds << " pounds " << shillings << " shillings " << pences << " pences " << "\n";
}

int british_currency::get_pounds() const { return pounds; }
int british_currency::get_shillings() const { return shillings; }
int british_currency::get_pences () const { return pences; }

void british_currency::set_pounds(int _pounds) {pounds = _pounds;}
void british_currency::set_shillings(int _shillings) {shillings = _shillings;}
void british_currency::set_pences(int _pences) {pences = _pences;}

british_currency add(const british_currency& bc1, const british_currency& bc2){
    british_currency bc;
    bc.set_pounds(bc1.get_pounds()+bc2.get_pounds());
    bc.set_pences(bc1.get_pences()+bc2.get_pences());
    bc.set_shillings(bc1.get_shillings()+bc2.get_shillings());
    bc.fix();
    return bc;
}
