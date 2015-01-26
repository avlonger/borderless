#ifndef PERIOD_UTILITIES_H_
#define PERIOD_UTILITIES_H_

#include <string>

// Returns longest borderless factor length using naive
// algorithm: test each factor of given word
int max_borderless_length_naive(const char * text, int n = -1);

// Returns longest borderless factor length
int max_borderless_length(const char * text, int n = -1);

#endif  // PERIOD_UTILITES_H_
