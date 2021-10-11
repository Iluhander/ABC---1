//
// Created by IlyaLayk on 10.10.2021.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "container.h"
#include "number.h"

// Container initialization.
void InitContainer(struct container *c, int size) {
    c -> size = size;
}

// Freeing up memory.
void ClearContainer(struct container *c) {
    c -> size = 0;
}

// Input from the thread given.
void InContainer(struct container *c, FILE* infile) {
    int size;
    fscanf(infile, "%d", &size);

    InitContainer(c, size);

    for (int i = 0; i < c -> size; ++i) {
        char numberType[9];
        fscanf(infile,"%s", numberType);

        if (!strcmp(numberType, "complex")) {
            InitNumber(&c -> elements[i], COMPLEX, NAN, NAN);
        } else if (!strcmp(numberType, "polar")) {
            InitNumber(&c -> elements[i], POLAR, NAN, NAN);
        } else if (!strcmp(numberType, "fraction")) {
            InitNumber(&c -> elements[i], FRACTION, NAN, NAN);
        } else {
            continue;
        }

        InNumber(&c -> elements[i], infile);
    }
}

// Random input.
void InRndContainer(struct container *c) {
    for (int i = 0; i < c -> size; ++i) {
        InRndNumber(&c -> elements[i]);
    }
}

// Output to the thread given.
void OutContainer(struct container *c, FILE* outfile) {
    for (int i = 0; i < c -> size; ++i) {
        OutNumber(&c -> elements[i], outfile);
        fprintf(outfile, "\n");
    }
}

// Safely getting element by index.
struct number* getElement(struct container* inp, int index) {
    if ((index >= 0) && (index < inp->size)) {
        return (inp->elements + index);
    } else {
        return NULL;
    }
}

// Safely setting element of the container.
void setElement(struct container *inp, int index, struct number *newValue) {
    if (index == inp -> size && index < 10000) {
        *(inp -> elements + inp -> size) = *newValue;

        inp -> size = inp -> size + 1;
    } else if (getElement(inp, index) != NULL) {
        *(inp -> elements + index) = *newValue;
    }
}

// Get results of casting all the elements to double.
void CastToDouble(struct container *c, double *output) {
    for (int i = 0; i < c -> size; ++i) {
        *(output + i) = toDouble(&c -> elements[i]);
    }
}

// Quick sort.
void QuickSort(struct container *c, int first, int last) {
    int i;
    int j;
    int k;

    struct number temp;

    if (first < last) {

        k = first;
        i = first;
        j = last;

        while (i < j) {

            while (toDouble(&c -> elements[i]) <= toDouble(&c -> elements[k]) && i < last) {
                ++i;
            }

            while (toDouble(&c -> elements[j]) > toDouble(&c -> elements[k])) {
                --j;
            }

            if (i < j) {
                temp = *getElement(c, i);
                setElement(c, i, &c -> elements[j]);
                setElement(c, j, &temp);
            }

        }

        temp = *getElement(c, k);
        setElement(c, k, &c -> elements[j]);
        setElement(c, j, &temp);

        QuickSort(c, first, j - 1);
        QuickSort(c, j + 1, last);
    }
}
