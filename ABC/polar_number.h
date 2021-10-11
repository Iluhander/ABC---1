//
// Created by IlyaLayk on 10.10.2021.
//

#ifndef ABC_POLAR_NUMBER_H
#define ABC_POLAR_NUMBER_H

#include <stdio.h>

struct polar_number {
    double angle;
    double x;
};

// Polar initialization.
void InitPolar(struct polar_number* inp, double angle, double x);

// Input from the thread given.
void InPolar(struct polar_number *inp, FILE* infile);

// Random input.
void InRndPolar(struct polar_number *inp);

// Output to the thread given.
void OutPolar(struct polar_number *inp, FILE* outfile);

// Cast to real.
double polarToReal (struct polar_number *inp);

#endif //ABC_POLAR_NUMBER_H
