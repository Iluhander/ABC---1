//
// Created by IlyaLayk on 15.10.2021.
//

#ifndef ABC_OO_FRACTION_NUMBER_H
#define ABC_OO_FRACTION_NUMBER_H

#include <fstream>
#include "number.h"
#include "randGenerator.h"

/// Fraction number class.
class FractionNumber : public Number {
 public:
    FractionNumber(int fstValue, int scndValue) : Number(fstValue, scndValue) {

    }

    /// Get double value.
    double CastToDouble() final;

    /// Print values.
    void Out(std::ofstream* outStream) final;

};

#endif //ABC_OO_FRACTION_NUMBER_H
