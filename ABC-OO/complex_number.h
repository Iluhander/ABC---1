//
// Created by IlyaLayk on 15.10.2021.
//

#ifndef ABC_OO_COMPLEX_NUMBER_H
#define ABC_OO_COMPLEX_NUMBER_H

#include <fstream>
#include "number.h"
#include "randGenerator.h"

/// Fraction number class.
class ComplexNumber : public Number {
public:
    ComplexNumber(double fstValue, double scndValue) : Number(fstValue, scndValue) {

    }

    /// Get double value.
    double CastToDouble();

    /// Print values.
    void Out(std::ofstream* outStream);

};
#endif //ABC_OO_COMPLEX_NUMBER_H
