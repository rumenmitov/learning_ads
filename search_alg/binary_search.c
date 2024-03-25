#include <math.h>

int binary_search(int haystack[], int len, int needle) {
    // NOTE: low is inclusive, high is exclusive
    int low = 0, high = len - 1;

    while (low < high) {
        // NOTE: floor is used only to remove floating point
        int midpoint = floor((low + high) / 2.0);

        if (haystack[midpoint] == needle) return 1;
        else if (haystack[midpoint] < needle) {
            // NOTE: remember that high is exclusive
            high = midpoint;
        } else {
            // NOTE: we do not need to cover midpoint, it is not the value
            low = midpoint + 1;
        }
    }

    return 0;
}
