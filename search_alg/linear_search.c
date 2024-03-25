int linear_search(int haystack[], int len, int needle) {
    for (int i = 0; i < len; ++i) {
        if (haystack[i] == needle) return 1;
    }

    return 0;
}
