//
// Created by IlyaLayk on 10.10.2021.
//

#include <stdlib.h>
#include <math.h>
#include "number.h"

// Number initialization.
void InitNumber(struct number *c, enum number_type type, double firstValue, double secondValue) {
    c -> type = type;

    if (type == COMPLEX) {
        InitComplex(&c -> value.complex, firstValue, secondValue);
    } else if (type == POLAR) {
        InitPolar(&c -> value.polar, firstValue, secondValue);
    } else if (type == FRACTION) {
        InitFraction(&c -> value.fraction, (int)firstValue, (int)secondValue);
    }
}

// Input from the thread given.
void InNumber(struct number *c, FILE* infile) {
    if (c -> type == COMPLEX) {
        InComplex(&c -> value.complex, infile);
    } else if (c -> type == POLAR) {
        InPolar(&c -> value.polar, infile);
    } else if (c -> type == FRACTION) {
        InFraction(&c -> value.fraction, infile);
    }
}

// Random input.
void InRndNumber(struct number *c) {
    if (c -> type == COMPLEX) {
        InRndComplex(&c -> value.complex);
    } else if (c -> type == POLAR) {
        InRndPolar(&c -> value.polar);
    } else if (c -> type == FRACTION) {
        InRndFraction(&c -> value.fraction);
    }
}

// Output to the thread given.
void OutNumber(struct number *c, FILE* outfile) {
    if (c -> type == COMPLEX) {
        OutComplex(&c -> value.complex, outfile);
    } else if (c -> type == POLAR) {
        OutPolar(&c -> value.polar, outfile);
    } else if (c -> type == FRACTION) {
        OutFraction(&c -> value.fraction, outfile);
    }
}

double toDouble (struct number *inp) {
    if (inp -> type == COMPLEX) {
        return complexToReal(&inp -> value.complex);
    } else if (inp -> type == FRACTION) {
        return fractionToReal(&inp -> value.fraction);
    } else if (inp -> type == POLAR) {
        return polarToReal(&inp -> value.polar);
    } else {
        return NAN;
    }
}
