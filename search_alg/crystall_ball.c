#include <math.h>

int crystal_ball(int haystack[], int len, int needle) {

    int index = 0;

    // iterate over array until 1st ball breaks
    while (!haystack[index] && index < len) {
        // NOTE: floor in case we do not get a natural number
        index += floor(sqrt(len));
    }

    // ball does not break case
    if (!haystack[index]) return -1;

    // go back to last checkpoint
    int breaks_at = index;
    index -= floor(sqrt(len));

    while (!haystack[index] && index < breaks_at) {
        index++;
    }

    return index;
}

// Time Complexity: O(sqrt(n))
