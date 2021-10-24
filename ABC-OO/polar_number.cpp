//
// Created by IlyaLayk on 23.10.2021.
//

#include "polar_number.h"

/// Get double value.
double PolarNumber::CastToDouble() {
    return firstValue / cos(secondValue);
}

/// Print values.
void PolarNumber::Out(std::ofstream* outStream) {
    *outStream << "Polar: (" << firstValue << ", " << secondValue << ")";
}