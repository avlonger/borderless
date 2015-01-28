#ifndef PERIOD_UTILITIES_H_
#define PERIOD_UTILITIES_H_

#include <string>

// Returns length of the longest unbordered factor using naive
// algorithm: test each factor of given word
int max_unbordered_length_naive(const char * text, int n = -1);

// Returns length of the longest unbordered factor
int max_unbordered_length(const char * text, int n = -1);

#endif  // PERIOD_UTILITES_H_
