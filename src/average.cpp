// average.cpp: Computation of the average length of the border or the maximal unbordered factor

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>

#include "unbordered.h"
#include "border.h"


// some buffers
char * CHAR_BUFFER;
int * INT_BUFFER;
int (* FUNCTION)();
char ALPHABET = 2;
char MINIMAL_CHAR = 1;
int START = 2;
int STEP = 1;
int FINISH = 10;
int LENGTH;
bool TRACE = false;
bool NORMALIZE = true;
bool PRINT_TOTAL = false;


void usage(const char * program_name) {
    printf("Usage: %s [options] ALGORITHM\n", program_name);
    printf("Calculate some average value for all words of given length\n");
    printf("Algorithms:\n");
    printf("UNBORDERED                find the average length of the longest\n");
    printf("                          unbordered factor for all words of given length\n");
    printf("UNBORDERED_NAIVE          naively find the average length of the longest\n");
    printf("                          unbordered factor for all words of given length\n");
    printf("UNBORDERED_DBF            find the average length of the longest\n");
    printf("                          unbordered factor for all words of given length\n");
    printf("                          using Dictionary of Basic Factors\n");
    printf("UNBORDERED_DBF_HASHTABLE  find the average length of the longest\n");
    printf("                          unbordered factor for all words of given length\n");
    printf("                          using Dictionary of Basic Factors and hashtable\n");
    printf("BORDER                    find the average border length\n");
    printf("                          for all words of given length\n");

    printf("\n");
    printf("Options:\n");
    printf(" -b  Minimal word length (default: 2)\n");
    printf(" -e  Maximal word length (default: 10)\n");
    printf(" -s  Word length step    (default: 1)\n");
    printf(" -a  Alphabet size       (default: 2)\n");
    printf(" -t  Trace: print results for all generated words\n");
    printf(" -n  Do not normalize result (do not divide result by the total words count)\n");
    printf(" -c  Print count of processed words\n");
    printf(" -h  Print this help message\n");
}


uint64_t do_for_all_words(int position) {
    uint64_t total = 0;
    int value = 0;
    for (char i = MINIMAL_CHAR; i < ALPHABET; ++i) {
        CHAR_BUFFER[position] = i;

        if (position < LENGTH - 1) {
            total += do_for_all_words(position + 1);
        } else {
            value = FUNCTION();

            if (TRACE) {
                printf("%s\t%d\n", CHAR_BUFFER, value);
            }

            total += value;
        }
    }

    return total;
}

int longest_unbordered_naive() {
    return max_unbordered_length_naive(CHAR_BUFFER, LENGTH);
}

int longest_unbordered() {
    return max_unbordered_length(CHAR_BUFFER, LENGTH);
}

int longest_unbordered_dbf() {
    return max_unbordered_length_dbf(CHAR_BUFFER, LENGTH);
}

int longest_unbordered_dbf_hashtable() {
    return max_unbordered_length_dbf_hashtable(CHAR_BUFFER, LENGTH);
}

int longest_border() {
    border(CHAR_BUFFER, INT_BUFFER, LENGTH);
    return INT_BUFFER[LENGTH - 1];
}

int main(int argc, char** argv) {
    int c = 0;
    opterr = 1;
    while ((c = getopt(argc, argv, "tnhce:b:s:a:")) != -1)
        switch (c)
        {
            case 'a':
                ALPHABET = (char) atoi(optarg);
                break;
            case 'e':
                FINISH = atoi(optarg);
                break;
            case 'b':
                START = atoi(optarg);
                break;
            case 's':
                STEP = atoi(optarg);
                break;
            case 't':
                TRACE = true;
                break;
            case 'n':
                NORMALIZE = false;
                break;
            case 'c':
                PRINT_TOTAL = true;
                break;
            case 'h':
                usage(argv[0]);
                return 0;
            case '?':
            case ':':
                return -1;
            default:
                usage(argv[0]);
                return -1;
        }

    if (TRACE) {
        MINIMAL_CHAR = 'A';
    }

    if (optind >= argc) {
        usage(argv[0]);
        return -1;
    }

    if (strcmp(argv[optind], "UNBORDERED") == 0) {
        FUNCTION = longest_unbordered;
    } else if (strcmp(argv[optind], "UNBORDERED_NAIVE") == 0) {
        FUNCTION = longest_unbordered_naive;
    } else if (strcmp(argv[optind], "UNBORDERED_DBF") == 0) {
        FUNCTION = longest_unbordered_dbf;
    } else if (strcmp(argv[optind], "UNBORDERED_DBF_HASHTABLE") == 0) {
        FUNCTION = longest_unbordered_dbf_hashtable;
    } else if (strcmp(argv[optind], "BORDER") == 0) {
        FUNCTION = longest_border;
    } else {
        usage(argv[0]);
        return -1;
    }

    CHAR_BUFFER = (char *) calloc((size_t) FINISH + 1, sizeof(char));
    INT_BUFFER = (int *) calloc((size_t) FINISH + 1, sizeof(int));

    ALPHABET += MINIMAL_CHAR;

    for (LENGTH = START; LENGTH < FINISH + 1; LENGTH += STEP) {

        uint64_t answer = do_for_all_words(0);

        double count = pow((double) (ALPHABET - MINIMAL_CHAR), (double) LENGTH);
        if (NORMALIZE) {
            printf("n = %d\tanswer = %.10f\n", LENGTH, (double) answer / count);
        } else {
            printf("n = %d\tanswer = %lld\n", LENGTH, answer);
        }

        if (PRINT_TOTAL) {
            printf("%d\n", (int) count);
        }

        fflush(stdout);
    }

    free(CHAR_BUFFER);
    free(INT_BUFFER);
    return 0;
}
