//
// Created by IlyaLayk on 10.10.2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "polar_number.h"

const double PI = 3.141592;
const double precision = 0.0000001;

// Polar initialization.
void InitPolar(struct polar_number* inp, double angle, double x) {
    inp -> angle = angle;
    inp -> x = x;
}

// Input from the thread given.
void InPolar(struct polar_number *inp, FILE* infile) {
    fscanf(infile, "%lf", &(inp -> angle));
    fscanf(infile, "%lf", &(inp -> x));
}

// Random input.
void InRndPolar(struct polar_number *inp) {
    srand(time(NULL));
    inp -> angle = PI * (2 * (double)rand()) / RAND_MAX;
    inp -> x = rand();

    // In case the angle is greater than pi / 2, x < 0.
    if (inp -> angle - PI / 2 > precision && inp -> angle - 3 * PI / 2 < precision) {
        inp -> x *= -1;
    } else if (abs(inp -> angle - PI / 2) <= precision) {
        inp -> x = 0;
    }

    if (abs(inp -> angle - (3 * PI) / 2) <= precision) {
        inp -> x = 0;
    }
}

// Output to the thread given.
void OutPolar(struct polar_number *inp, FILE* outfile) {
    fprintf(outfile, "(polar, %lf, %d)", inp -> angle, inp -> x);
}

// Cast to real.
double polarToReal (struct polar_number *inp) {
    return inp -> x / cos(inp -> angle);
}