//
// Created by Monica Stuart on 2018-10-16.
//

#include "fraction_15mxs1.h"
#include<iostream>
#include<string>
#include<cmath>


using namespace std;


FractionException::FractionException(const string &errorMessage) :
        errorMessage(errorMessage) {
}

//returns error message if exception is thrown
string &FractionException::what() {
    return errorMessage;
}

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n) : num(n), den(1) {}

Fraction::Fraction(int n, int d) {
    if (d == 0) {
        throw FractionException("[Error] Divide by zero error");
    }

    //checks if fraction can be reduced to its lowest terms
    gcd(n, d);

}

int Fraction::numerator() const { return num; }

int Fraction::denominator() const { return den; }

ostream &operator<<(ostream &out, const Fraction &value) {

    out << value.numerator() << " / " << value.denominator();
    return out;
}

istream &operator>>(istream &in, Fraction &fraction) {

    //denominator of user inputted fraction
    int dFrac;

    //numerator of user inputted fraction
    int nFrac;

    std::string inputline;
    if (in >> inputline) {
        int num_read = sscanf(inputline.c_str(), "%d/%d", &nFrac, &dFrac);
        if (num_read > 0) {
            //checks if whole number fraction
            if (num_read < 2) {
                dFrac = 1;
            }
            //initialize numerator and denominator of user inputted fraction
            fraction = Fraction(nFrac, dFrac);
        } else {
            in.setstate(std::ios::failbit);
        }
    }
    return in;
}


Fraction operator/(const Fraction &firstFraction, const Fraction &secondFraction) {

    int multNum = firstFraction.numerator() * secondFraction.denominator();
    int multDen = firstFraction.denominator() * secondFraction.numerator();

    return Fraction(multNum, multDen);
}

Fraction operator*(const Fraction &firstFraction, const Fraction &secondFraction) {

    int multNum = firstFraction.numerator() * secondFraction.numerator();
    int multDen = firstFraction.denominator() * secondFraction.denominator();

    return Fraction(multNum, multDen);
}


Fraction operator-(const Fraction &firstFraction, const Fraction &secondFraction) {

    //numerator of subtracted fractions
    int multNum = (firstFraction.numerator() * secondFraction.denominator()) -
                  (firstFraction.denominator() * secondFraction.numerator());

    //denominator of subtracted fractions
    int multDen = firstFraction.denominator() * secondFraction.denominator();

    //return reduced fraction
    return Fraction(multNum, multDen);
}

Fraction operator+(const Fraction &firstFraction, const Fraction &secondFraction) {

    int multNum = (firstFraction.numerator() * secondFraction.denominator()) +
                  (firstFraction.denominator() * secondFraction.numerator());
    int multDen = firstFraction.denominator() * secondFraction.denominator();

    return Fraction(multNum, multDen);
}

Fraction operator-(const Fraction &firstFraction) {
    Fraction test = Fraction(-1, 1);

    //multiply fraction by -1
    Fraction fTest = firstFraction * test;

    return fTest;
}

//pre increment operator overloader
Fraction &Fraction::operator++() {
    num = num + den;

    return *this;
}

//post increment operator overloader
Fraction Fraction::operator++(int unused) {

    Fraction postIncFrac(num, den);
    //add 1/1
    num = num + den;


    return postIncFrac;
}

Fraction &Fraction::operator+=(const Fraction &right) {

    //add fraction on right side of operator fraction to the left
    *this = *this + right;

    return *this;
}

bool operator==(const Fraction &firstFraction, const Fraction &secondFraction) {
    if ((firstFraction.numerator() == secondFraction.numerator()) &&
        (firstFraction.denominator() == secondFraction.denominator())) {
        return true;
    }
    else {
        return false;
    }
}

bool operator!=(const Fraction &firstFraction, const Fraction &secondFraction) {
    if ((firstFraction.numerator() != secondFraction.numerator()) &&
        (firstFraction.denominator() != secondFraction.denominator())) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>(const Fraction &firstFraction, const Fraction &secondFraction) {

    //compare the common multiple version of fractions' numerators to see if the fraction on the left hand side of the operator is greater
    if ((firstFraction.numerator() * secondFraction.denominator()) >
        secondFraction.numerator() * firstFraction.denominator()) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<(const Fraction &firstFraction, const Fraction &secondFraction) {

    //compare the common multiple version of fractions' numerators to see if the fraction on the left hand side of the operator is smaller
    if ((firstFraction.numerator() * secondFraction.denominator()) <
        secondFraction.numerator() * firstFraction.denominator()) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>=(const Fraction &firstFraction, const Fraction &secondFraction) {


    if ((firstFraction.numerator() * secondFraction.denominator()) >
        (secondFraction.numerator() * firstFraction.denominator())) {
        return true;
    }
    if ((firstFraction.numerator() == secondFraction.numerator()) &&
        (firstFraction.denominator() == secondFraction.denominator())) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<=(const Fraction &firstFraction, const Fraction &secondFraction) {

    if ((firstFraction.numerator() * secondFraction.denominator()) <
        (secondFraction.numerator() * firstFraction.denominator())) {
        return true;
    }
    if ((firstFraction.numerator() == secondFraction.numerator()) &&
        (firstFraction.denominator() == secondFraction.denominator())) {
        return true;
    }
    else {
        return false;
    }
}

void Fraction::gcd(int n, int d) {

    //if denominator is negative
    if (d < 0) {

        //set the numerator and denominator to initial respective values in case fraction cannot be reduced
        num = n;
        den = d;

        //finds the greatest common multiple that divides evenly into both fractions
        for (int i = (n * -1) * d; i > 1; i--) {
            if ((n % i == 0) && (d % i == 0)) {
                num = n / (-i);
                den = d / (-i);
                i = 0;
            }
        }

    }
    //if numerator is negative
    else if (n < 0) {
        num = n;
        den = d;
        for (int i = n * (d * -1); i > 1; i--) {
            if ((n % i == 0) && (d % i == 0)) {
                num = n / i;
                den = d / (-i);
                i = 0;
            }
        }

    }
    else {
        num = n;
        den = d;
        for (int i = n * d; i > 0; i--) {
            if ((n % i == 0) && (d % i == 0)) {
                num = n / i;
                den = d / i;
                i = 0;
            }
        }
    }
}