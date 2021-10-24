//
// Created by IlyaLayk on 24.10.2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include "container.h"
#include "complex_number.h"
#include "polar_number.h"
#include "fraction_number.h"

// Container initialization.
void Container::Init(int newSize) {
    size = newSize;

    elements = new Number*[size];
}

// Freeing up memory.
void Container::Clear() {
    size = 0;
}

// Input from the thread given.
void Container::In(std::ifstream *inputStream) {
    int newSize;
    (*inputStream) >> newSize;
    Init(newSize);

    std::string numberType;
    for (int i = 0; i < size; ++i) {
        *inputStream >> numberType;

        Number* newElement;
        if (numberType == "complex") {
            newElement = new ComplexNumber(0, 0);
        } else if (numberType == "polar") {
            newElement = new PolarNumber(0, 0);
        } else if (numberType == "fraction") {
            newElement = new FractionNumber(0, 0);
        } else {
            continue;
        }

        elements[i] = newElement;
        elements[i] -> In(inputStream);
    }
}

// Random input.
void Container::InRand(int newSize) {
    size = newSize;

    Init(newSize);

    for (int i = 0; i < size; ++i) {
        elements[i] = Number::InRand();
    }
}

// Output to the thread given.
void Container::Out(std::ofstream *outStream) {
    for (int i = 0; i < size; ++i) {
        auto complex = dynamic_cast<ComplexNumber*>(elements[i]);
        auto polar = dynamic_cast<PolarNumber*>(elements[i]);
        auto fraction = dynamic_cast<FractionNumber*>(elements[i]);

        if (complex != nullptr) {
            complex -> Out(outStream);
            *outStream << "; Function value = " << complex -> CastToDouble();
        } else if (polar != nullptr) {
            polar -> Out(outStream);
            *outStream << "; Function value = " << polar -> CastToDouble();
        } else if (fraction != nullptr) {
            fraction -> Out(outStream);
            *outStream << "; Function value = " << fraction -> CastToDouble();
        }

        *outStream << '\n';
    }
}

// Safely getting element by index.
Number* Container::getElement(int index) {
    if ((index >= 0) && (index < size)) {
        return elements[index];
    } else {
        return nullptr;
    }
}

// Safely setting element of the container.
void Container::setElement(int index, Number *newValue) {
    if (index == size && index < 10000) {
        *(elements + size) = newValue;

        size = size + 1;
    } else if (getElement(index) != nullptr) {
        *(elements + index) = newValue;
    }
}

// The function given (O(size)).
void Container::RemoveLessThanAverage() {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += elements[i] -> CastToDouble();
    }

    double averageValue = sum / size;

    int sizeDelta = 0;
    for (int i = 0, j = 0; i < size; ++i) {
        if ((elements[i] -> getFirstValue() <= (double)INT32_MAX) && (elements[i] -> CastToDouble() >= averageValue)) {
            elements[j] = elements[i];

            if (j < i) {
                elements[i] = new Number();
            }

            ++j;
        } else {
            sizeDelta = sizeDelta + 1;
        }
    }

    size -= sizeDelta;
}

Container::Container() {

}
