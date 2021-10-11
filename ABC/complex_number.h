//
// Created by IlyaLayk on 10.10.2021.
//

#ifndef ABC_COMPLEX_NUMBER_H
#define ABC_COMPLEX_NUMBER_H

#include <stdio.h>

struct complex_number {
    double real;
    double imaginary;
};

// Polar initialization.
void InitComplex(struct complex_number* inp, double real, double imaginary);

// Input from the thread given.
void InComplex(struct complex_number *inp, FILE* infile);

// Random input.
void InRndComplex(struct complex_number *inp);

// Output to the thread given.
void OutComplex(struct complex_number *inp, FILE* outfile);

// Casting complex number to double.
double complexToReal(struct complex_number *inp);

#endif //ABC_COMPLEX_NUMBER_H
