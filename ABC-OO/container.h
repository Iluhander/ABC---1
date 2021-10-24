//
// Created by IlyaLayk on 15.10.2021.
//

#ifndef ABC_OO_CONTAINER_H
#define ABC_OO_CONTAINER_H

#include <fstream>
#include "container.h"
#include "number.h"
#include "complex_number.h"
#include "polar_number.h"
#include "fraction_number.h"

class Container {
public:
    Container();

    // Container initialization.
    void Init(int newSize);

    // Freeing up memory.
    void Clear();

    // Input from the thread given.
    void In(std::ifstream *inputStream);

    // Random input.
    void InRand(int newSize);

    // Output to the thread given.
    void Out(std::ofstream *outStream);

    // Safely getting element by index.
    Number* getElement(int index);

    // Safely setting element of the container.
    void setElement(int index, Number *newValue);

    // The function given.
    void RemoveLessThanAverage();

private:
    int size;

    Number** elements;
};

#endif //ABC_OO_CONTAINER_H
