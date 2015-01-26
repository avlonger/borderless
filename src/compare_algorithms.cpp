// compare_algorithms.cpp: Compare time required by the algorithms

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctime>

#include "borderless.h"

void usage(const char * program_name) {
    printf("Usage: %s [options]\n", program_name);
    printf("Compare time required by proposed algorithms\n");
    printf("Options:\n");
    printf(" -b  Minimal word length            (default: 100)\n");
    printf(" -e  Maximal word length            (default: 1000)\n");
    printf(" -s  Word length step               (default: 1)\n");
    printf(" -a  Alphabet size                  (default: 2)\n");
    printf(" -r  Random words count for testing (default: 1000)\n");
    printf(" -t  Trace: print results for all generated words\n");
    printf(" -h  Print this help message\n");

}


void fill_rand_chars(char *str, int n, int alphabet_size, char minimal_char) {
    for (int i = 0; i < n; ++i)
        str[i] = (char) (rand() % alphabet_size) + minimal_char;
}


void measure(char alphabet, char minimal_char, int length, int words_count, bool trace) {

    // fill words_count strings with random letters
    char * strings = (char *) calloc(length * words_count, sizeof(char));
    fill_rand_chars(strings, length * words_count, alphabet, minimal_char);


    clock_t begin = clock();

    for (int i = 0; i < words_count; ++i) {
        int result = max_borderless_length(strings + i * length, length);
        if (trace)
            printf("%.*s %d\n", length, strings + i * length, result);
    }
    printf("BASIC_ALGORITHM: n = %d t = %.8f\n", length, double(clock() - begin) / CLOCKS_PER_SEC / words_count);
    fflush(stdout);

    begin = clock();

    for (int i = 0; i < words_count; ++i) {
        int result = max_borderless_length_naive(strings + i * length, length);
        if (trace)
            printf("%.*s %d\n", length, strings + i * length, result);
    }

    printf("NAIVE_ALGORITHM: n = %d t = %.8lf\n", length, double(clock() - begin) / CLOCKS_PER_SEC / words_count);
    fflush(stdout);

    free(strings);
}


int main(int argc, char** argv) {
    int c = 0;
    opterr = 1;
    char alphabet = 2;
    int start = 100;
    int finish = 1000;
    int step = 1;
    bool trace = false;
    int words_count = 1000;
    char minimal_char = 1;
    while ((c = getopt(argc, argv, "thb:e:s:a:r:")) != -1)
        switch (c)
        {
            case 'a':
                alphabet = (char) atoi(optarg);
                break;
            case 'b':
                start = atoi(optarg);
                break;
            case 'e':
                finish = atoi(optarg);
                break;
            case 's':
                step = atoi(optarg);
                break;
            case 't':
                trace = true;
                minimal_char = 'A';
                break;
            case 'h':
                usage(argv[0]);
                return 0;
            case 'r':
                words_count = atoi(optarg);
                break;
            case '?':
            case ':':
                return -1;
            default:
                usage(argv[0]);
                return -1;
        }

    for (int length = start; length < finish + 1; length += step) {
        measure(alphabet, minimal_char, length, words_count, trace);
    }

    return 0;
}
