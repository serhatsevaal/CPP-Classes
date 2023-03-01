#pragma once
#include <iostream>
using namespace std;

class Fraction
{
    
private:
	int nominator;
	int denominator;
public:
    Fraction();
    Fraction(int n, int m);
    int get_nominator() const;
    void set_nominator(int i);
    int get_denominator() const;
    void set_denominator(int i);
	void read();
	void write() const;
	void shorten();
    friend istream& operator>>(istream& in, Fraction& u);
};

int gcd(int a, int b);
Fraction add(Fraction a, Fraction b);

ostream& operator<<(ostream& out, Fraction u);
