//
// Created by IlyaLayk on 10.10.2021.
//

#ifndef ABC_CONTAINER_H
#define ABC_CONTAINER_H

#include "number.h"

struct container {
    int size;

    // Container elements;
    struct number elements[10000];
};

// Container initialization.
void InitContainer(struct container *c, int size);

// Freeing up memory.
void ClearContainer(struct container *c);

// Input from the thread given.
void InContainer(struct container *c, FILE* infile);

// Random input.
void InRndContainer(struct container *c);

// Output to the thread given.
void OutContainer(struct container *c, FILE* outfile);

// Safely getting element by index.
struct number* getElement(struct container *inp, int index);

// Safely setting element of the container.
void setElement(struct container *inp, int index, struct number *newValue);

// Get results of casting all the elements to double.
void CastToDouble(struct container *c, double *output);

// Quick sort.
void QuickSort(struct container *c, int first, int last);

#endif //ABC_CONTAINER_H
