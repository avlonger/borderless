#include "borderless.h"

#include <stdlib.h>

#include "border.h"


int max_borderless_length_naive(const char * text, int n) {
    if (n < 0) {
        n = (int) strlen(text);
    }
    int * border_buffer = (int *) calloc(n, sizeof(int));

    int max_len = 1;

    for (int i = 0; i < n - 1; ++i) {
        border(text + i, border_buffer, n - i);

        for (int j = n - i; j > i; --j)
            if (border_buffer[j - 1] == 0 && j > max_len)
                max_len = j;
    }
    free(border_buffer);
    return max_len;
}


int max_borderless_length(const char * text, int n) {

    if (n < 0) {
        n = (int) strlen(text);
    }

    int * border_buffer = (int *) calloc(n, sizeof(int));

    int max_len = 1;

    for (int k = 0; k < n && n - k > max_len; ++k) {

        const char * suffix = text + k;

        border_buffer[0] = 0;
        int j = 0;
        for (int i = 1; i < n - k; ++i) {

            j = border_buffer[i - 1];

            while (j > 0 && suffix[i] != suffix[j]) {
                j = border_buffer[j - 1];
            }

            if (suffix[i] == suffix[j])
                j++;

            border_buffer[i] = j;

            if (j == 0 && i + 1 > max_len) {
                max_len = i + 1;
            }
        }
    }
    free(border_buffer);
    return max_len;
}
