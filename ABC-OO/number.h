//
// Created by IlyaLayk on 15.10.2021.
//

#ifndef ABC_OO_NUMBER_H
#define ABC_OO_NUMBER_H

#include <iostream>
#include <fstream>
#include "randGenerator.h"

class Number {
protected:
    static RandomGenerator<double> rand1337;

    static int a;

    double firstValue;
    double secondValue;
public:
    Number() {
        firstValue = (double)INT32_MAX + 1;
        secondValue = (double)INT32_MAX + 1;
    }

    Number(double fstValue, double scndValue) {
        firstValue = fstValue;
        secondValue = scndValue;
    }

    /// Generate fields values randomly.
    static Number* InRand();

    /// Cast the number to double.
    virtual double CastToDouble() {
        return (double)INT32_MAX + 1;
    }

    /// Get values.
    virtual void In(std::ifstream* inStream) {
        (*inStream) >> firstValue >> secondValue;
    }

    /// Print values.
    virtual void Out(std::ofstream* outStream) {

    }

    /// Accessor to the first value.
    double getFirstValue();

     /// Accessor to the second value.
     double getSecondValue();
};

#endif //ABC_OO_NUMBER_H
