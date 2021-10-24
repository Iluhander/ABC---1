//
// Created by IlyaLayk on 23.10.2021.
//

#ifndef ABC_OO_RANDGENERATOR_H
#define ABC_OO_RANDGENERATOR_H

#include <cstdlib>
#include <ctime>   // для функции time()

/// Generator of random values.
template <typename T>
class RandomGenerator {
public:
    RandomGenerator(T first, T last) {
        if(first <= last) {
            minValue = first;
            maxValue = last;
        } else {
            minValue = last;
            maxValue = first;
        }

        // Initializing with system clock.
        srand(static_cast<unsigned int>(time(0)));
    }

    /// Generating random number in the range given.
    T GenerateValue() {
        return rand() % (maxValue - minValue + 1) + minValue;
    }

private:
    int minValue;
    int maxValue;
};

#endif //ABC_OO_RANDGENERATOR_H
