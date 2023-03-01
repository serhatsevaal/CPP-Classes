#include <iostream>
using namespace std;
#include "fraction.h"

int gcd (int a, int b){
    int r = 1;
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

Fraction::Fraction() : nominator(0), denominator(1){}

Fraction:: Fraction(int n, int d){
    this->nominator = n;
    this->denominator = d;
}

void Fraction::read(){
    
    cout << "Enter nominator: ";
    cin >> this->nominator;
    do {
        cout << "Enter denominator: ";
        cin >> this->denominator;
    }
    while(this->denominator == 0);
}

void Fraction::write() const{
    cout << this->nominator << "/" << this->denominator << "\n";
}

void Fraction::shorten(){
    int greatestCommon = gcd(this->nominator, this->denominator);
    this->nominator = this->nominator/greatestCommon;
    this->denominator = this->denominator/greatestCommon;
}

int Fraction::get_denominator() const{
    return this->denominator;
}

int Fraction::get_nominator() const{
    return this->nominator;
}

void Fraction::set_nominator(int i){
    this->nominator = i;
}

void Fraction::set_denominator(int i){
    this->denominator = i;
}

Fraction add(Fraction a, Fraction b){
    Fraction result;
    result.set_nominator((a.get_nominator()*b.get_denominator())+(b.get_nominator()*a.get_denominator()));
    result.set_denominator(a.get_denominator()*b.get_denominator());
    result.shorten();
    return result;
}

ostream& operator<<(ostream& out, Fraction u){
    u.shorten();
    out<<u.get_nominator()<<"/"<<u.get_denominator()<<"\n";
    return out;
}

istream& operator>>(istream& in, Fraction& u){
    int n,d;
    cout << "Enter nominator: ";
    in >> u.nominator;
    do{
        cout << "Enter denominator: ";
        in >> u.denominator;}
    while(u.denominator == 0);
    return in;
}
