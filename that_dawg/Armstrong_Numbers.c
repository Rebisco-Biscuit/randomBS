/* From Exercism, Armstrong Numbers */

#include "armstrong_numbers.h"
#include <stdlib.h>
#include <math.h>

bool is_armstrong_number(int candidate) {
    int copy = candidate;
    int result = 0, x = 0;

    while (candidate != 0) {
        candidate /= 10;
        x++;
    }

    int *arr = malloc(sizeof(int) * x);

    candidate = copy;
    for (int i = 0; i < x; i++) {
        arr[i] = candidate % 10;
        candidate /= 10;
    }

    for (int i = 0; i < x; i++) {
        result += pow(arr[i], x);
    }

    free(arr);

    return result == copy;
}
