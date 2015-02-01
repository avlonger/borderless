#ifndef PERIOD_UTILITIES_H_
#define PERIOD_UTILITIES_H_

#include "dbf.h"

// Returns length of the longest unbordered factor using naive
// algorithm: test each factor of given word
int max_unbordered_length_naive(const char * text, int n = -1);

// Returns length of the longest unbordered factor
int max_unbordered_length(const char * text, int n = -1);

// Returns length of longest unbordered subword of given word
// using Dictionary of Basic Factors data structure
int max_unbordered_length_dbf(const char * text, int n = -1);

// Returns length of longest unbordered subword of given word
// using Dictionary of Basic Factors data structure
// and hash table for basic factors position storing
int max_unbordered_length_dbf_hashtable(const char * text, int n = -1);

// Returns true if given factor of text is unbordered and
// false otherwise, based on using Dictionary of Basic Factors
bool is_unbordered(const char * text, DBF & dbf, int start, int end);

#endif  // PERIOD_UTILITES_H_
