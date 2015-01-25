#include <stdlib.h>
#include <string.h>

void border(const char * text, int * border, int n) {
    if (n < 0) {
        n = (int) strlen(text);
    }
    border[0] = 0;
    int j = 0;
    for (int i = 1; i < n; ++i) {
        j = border[i - 1];
        while (j > 0 && text[i] != text[j]) {
            j = border[j - 1];
        }
        if (text[i] == text[j])
            j++;
        border[i] = j;
    }
}
