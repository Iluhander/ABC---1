//
// Created by IlyaLayk on 23.10.2021.
//

#include <cmath>
#include "complex_number.h"

/// Get double value.
double ComplexNumber::CastToDouble() {
    return sqrt(firstValue * firstValue + secondValue * secondValue);
}

/// Print values.
void ComplexNumber::Out(std::ofstream* outStream) {
    *outStream << "Complex: (" << firstValue << ", " << secondValue << ")";
}