#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "complex_number.h"

// Polar initialization.
void InitComplex(struct complex_number* inp, double real, double imaginary) {
    inp -> real = real;
    inp -> imaginary = imaginary;
}

// Input from the thread given.
void InComplex(struct complex_number *inp, FILE* infile) {
    fscanf(infile, "%lf", &(inp -> real));
    fscanf(infile, "%lf", &(inp -> imaginary));
}

// Random input.
void InRndComplex(struct complex_number *inp) {
    srand(time(NULL));

    inp -> real = rand() - rand();
    inp -> imaginary = rand() - rand();
}

// Output to the thread given.
void OutComplex(struct complex_number *inp, FILE* outfile) {
    fprintf(outfile, "(complex, %lf + i * %lf)", inp -> real, inp -> imaginary);
}

// Casting complex number to double.
double complexToReal(struct complex_number *inp) {
    return sqrt(inp -> imaginary * inp -> imaginary + inp -> real * inp -> real);
}
