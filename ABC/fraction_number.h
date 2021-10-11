//
// Created by IlyaLayk on 10.10.2021.
//

#ifndef ABC_FRACTION_NUMBER_H
#define ABC_FRACTION_NUMBER_H

#include <stdio.h>

struct fraction_number {
    int numerator;
    int denominator;
};

// Polar initialization.
void InitFraction(struct fraction_number* inp, int numerator, int denominator);

// Input from the thread given.
void InFraction(struct fraction_number *inp, FILE* infile);

// Random input.
void InRndFraction(struct fraction_number *inp);

// Output to the thread given.
void OutFraction(struct fraction_number *inp, FILE* outfile);

// Casting fraction to double.
double fractionToReal (struct fraction_number *inp);

#endif //ABC_FRACTION_NUMBER_H
