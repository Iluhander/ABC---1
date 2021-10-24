#include "fraction_number.h"

/// Get double value.
double FractionNumber::CastToDouble() {
    return firstValue / secondValue;
}

/// Print values.
void FractionNumber::Out(std::ofstream* outStream) {
    *outStream << "Fraction: (" << firstValue << "/" << secondValue << ")";
}