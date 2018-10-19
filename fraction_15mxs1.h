//
// Created by Monica Stuart on 2018-10-16.
//

#ifndef ASSIGNMENT2_FRACTION_15MXS1_H
#define ASSIGNMENT2_FRACTION_15MXS1_H

#endif //ASSIGNMENT2_FRACTION_15MXS1_H

//constructor that takes in numerator and denominator and reduces to lcm
//cout << operator overloader
//divide by zero error
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

class Fraction {
public:
    //constructors
    Fraction();
    Fraction(int);
    Fraction(int, int);

    //accessors
    int numerator() const;
    int denominator() const;

    //overloading unary operators that require access to the private variables
    Fraction operator++(int);
    Fraction &operator++();

    //overload binary operator that requires access to the private variables
    Fraction &operator+=(const Fraction &right);

    //function that reduces the fraction to its lowest terms
    void gcd(int n, int d);

private:
    //stores numerator
    int num;
    //stores denominator
    int den;

};

//if denominator of fraction is zero (divide by zero error) FractionException is thrown
class FractionException {
public:
    FractionException(const string &errorMessage);

    string &what();

private:
    string errorMessage;
};

// overload unary operator (-)
Fraction operator-(const Fraction &firstFraction);

//overload binary operators
ostream &operator<<(ostream &out, const Fraction &value);
istream &operator>>(istream &in, Fraction &fraction);
Fraction operator+(const Fraction &firstFraction, const Fraction &secondFraction);
Fraction operator-(const Fraction &firstFraction, const Fraction &secondFraction);
Fraction operator*(const Fraction &firstFraction, const Fraction &secondFraction);
Fraction operator/(const Fraction &firstFraction, const Fraction &secondFraction);

//overload binary operators that return a bool statement
bool operator==(const Fraction &firstFraction, const Fraction &secondFraction);
bool operator!=(const Fraction &firstFraction, const Fraction &secondFraction);
bool operator>(const Fraction &firstFraction, const Fraction &secondFraction);
bool operator<(const Fraction &firstFraction, const Fraction &secondFraction);
bool operator>=(const Fraction &firstFraction, const Fraction &secondFraction);
bool operator<=(const Fraction &firstFraction, const Fraction &secondFraction);

