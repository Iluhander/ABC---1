#include <iostream>
#include <cstring>
#include "container.h"

using std::cout;

void errMessageCommand() {
    printf("Incorrect command line!\n"
           "\n  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessageQualifier() {
    printf("Incorrect qualifier value!\n"
           "\n  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

int main(int argc, char* argv[]) {
    // Starting the timer.
    unsigned int start_time = clock();

    if(argc != 5) {
        errMessageCommand();
        return 1;
    }

    cout << "Start"<< std::endl;
    Container elements;

    // Creating the container.
    if(!strcmp(argv[1], "-f")) {
        std::ifstream inputStream(argv[2]);

        elements.In(&inputStream);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);

        if((size < 1) || (size > 10000)) {
            cout << "Incorrect number of elements = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }

        // Filling the container with random elements.
        elements.InRand(size);
    }
    else {
        errMessageQualifier();
        return 2;
    }

    // Printing container.
    std::ofstream outStream1(argv[3]);
    outStream1 << "Filled container:\n";
    elements.Out(&outStream1);

    // Applying the function given.
    elements.RemoveLessThanAverage();

    // Printing container after applying the function given.
    std::ofstream outStream2(argv[4]);
    outStream2 << "Container without elements that are less than average:\n";
    elements.Out(&outStream2);

    // Counting and print of the time spent.
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Stop. ";
    cout << search_time;
    cout << " ms passed.";

    return 0;
}
