//
// Created by IlyaLayk on 24.10.2021.
//

#include <iostream>
#include "randGenerator.h"
#include "number.h"
#include "complex_number.h"
#include "polar_number.h"
#include "fraction_number.h"

RandomGenerator<double> Number::rand1337(0, 1337);

/// Accessor to the first value.
double Number::getFirstValue() {
    return firstValue;
}

/// Accessor to the second value.
double Number::getSecondValue() {
    return secondValue;
}

/// Generate fields values randomly.
Number* Number::InRand() {
    int newNumberType = rand1337.GenerateValue();

    Number* newNumber;
    if (newNumberType < 450) {
        newNumber = new ComplexNumber(rand1337.GenerateValue(), rand1337.GenerateValue());
    } else if (newNumberType < 900) {
        newNumber = new PolarNumber(rand1337.GenerateValue(), rand1337.GenerateValue());
    } else {
        newNumber = new FractionNumber(rand1337.GenerateValue(), rand1337.GenerateValue());
    }

    return newNumber;
}