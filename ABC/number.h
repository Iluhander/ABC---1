//
// Created by IlyaLayk on 10.10.2021.
//

#ifndef ABC_NUMBER_H
#define ABC_NUMBER_H

#include <stdio.h>
#include "complex_number.h"
#include "fraction_number.h"
#include "polar_number.h"

struct number {
    enum number_type {
        COMPLEX,
        FRACTION,
        POLAR
    } type;

    union value_type {
        struct complex_number complex;
        struct fraction_number fraction;
        struct polar_number polar;
    } value;
};

// Number initialization.
void InitNumber(struct number *c, enum number_type type, double firstValue, double secondValue);

// Input from the thread given.
void InNumber(struct number *c, FILE* infile);

// Random input.
void InRndNumber(struct number *c);

// Output to the thread given.
void OutNumber(struct number *c, FILE* outfile);

// Cast to real function.
double toDouble(struct number *inp);

#endif //ABC_NUMBER_H
