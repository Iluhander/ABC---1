#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "container.h"

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

    if (argc != 5) {
        errMessageCommand();
        return 1;
    }

    printf("Start\n");
    struct container elements;

    if (!strcmp(argv[1], "-f")) {
        FILE* infile = fopen(argv[2], "r");
        InContainer(&elements, infile);
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("Incorrect number of elements = %d."
                   "Set 0 < number <= 10000\n", size);
            return 3;
        }

        InitContainer(&elements, size);

        // System clock.
        srand(time(NULL));

        // Filling the container randomly.
        InRndContainer(&elements);
    } else {
        errMessageQualifier();
        return 2;
    }

    // Printing.
    FILE* outfile1 = fopen(argv[3], "w");
    fprintf(outfile1, "Filled container:\n");
    OutContainer(&elements, outfile1);

    // Getting doubles.
    FILE* outfile2 = fopen(argv[4], "w");
    fprintf(outfile2, "Numeric values of container elements:\n");

    double *casted = malloc(elements.size);
    CastToDouble(&elements, &casted[0]);
    for (int i = 0; i < elements.size; ++i) {
        fprintf(outfile2, "%lf\n" , *(casted + i));
    }

    fprintf(outfile2, "\nSorted container:\n");
    // Sorting the container.
    QuickSort(&elements, 0, elements.size - 1);

    OutContainer(&elements, outfile2);

    // Final actions.
    ClearContainer(&elements);

    // Counting and print of the time spent.
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    printf("Stop\n");
    printf("%d",search_time);

    return 0;
}
