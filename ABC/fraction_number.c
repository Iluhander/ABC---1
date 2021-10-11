//
// Created by IlyaLayk on 10.10.2021.
//

#include <time.h>
#include <stdlib.h>
#include "fraction_number.h"

// Polar initialization.
void InitFraction(struct fraction_number* inp, int numerator, int denominator) {
    inp -> numerator = numerator;
    inp -> denominator = denominator;
}

// Input from the thread given.
void InFraction(struct fraction_number *inp, FILE* infile) {
    fscanf(infile, "%i", &(inp -> numerator));
    fscanf(infile, "%i", &(inp -> denominator));;
}

// Random input.
void InRndFraction(struct fraction_number *inp) {
    srand(time(NULL));
    inp -> numerator = rand();
    inp -> numerator = (rand()) % RAND_MAX + 1;
}

// Output to the thread given.
void OutFraction(struct fraction_number *inp, FILE* outfile) {
    fprintf(outfile, "(fraction, %d / %d)", inp -> numerator, inp -> denominator);
}


double fractionToReal(struct fraction_number *inp) {
    return (inp -> numerator) / ((double)inp -> denominator);
}