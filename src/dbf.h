#ifndef DICTIONARY_OF_BASIC_FACTORS_H_
#define DICTIONARY_OF_BASIC_FACTORS_H_

#include <vector>
#include <array>
#include <unordered_map>

using std::vector;
using std::array;
using std::unordered_map;

// Dictionary of Basic Factors
// M.Crochemore "Jewels of Stringology", p.85
class DBF {
public:
    // default constructor
    DBF();

    // Creates a new DBF data structure for given text
    // using Karp-Miller-Rosenberg algorithm
    // it requires O(n log n) time and space
    DBF(const char * text, int n = -1);

    // Returns the first occurrence of
    // basic factor for given id and length k
    // that is not less than i
    int succ(int i, int k, int id);

    // Returns the last occurrence of
    // basic factor for given id and length k
    // that is not greater than i
    int pred(int i, int k, int id);

    // Returns id of basic factor
    // starting in position i
    // having length k
    int id(int i, int k);

    // Returns the last occurrence of
    // basic factor v for given id from range
    // [i - |v|, i]
    virtual int pred_short(int i, int k, int id);

    // Returns the last occurrence of
    // basic factor v for given id from range
    // [i, i + |v|]
    virtual int succ_short(int i, int k, int id);

protected:

    virtual void __build_dbf(const char * text, int n);

    // fill positions data structure with
    // freshly-generated basic factor ids
    virtual void fill_positions(int k, int ids_count);

    // ids of basic factors
    vector< vector<int> > ids;

    // positions of basic factors
    vector< vector< vector<int> > > pos;

};


// hash function for integer triplet
namespace std
{
    template<typename T, size_t N>
    struct hash<array<T, N> >
    {
        typedef array<T, N> argument_type;
        typedef size_t result_type;

        result_type operator()(const argument_type& a) const
        {
            hash<T> hasher;
            result_type h = 0;
            for (result_type i = 0; i < N; ++i)
            {
                h = h * 499 + hasher(a[i]);
            }
            return h;
        }
    };
}


// Dictionary of Basic Factors
// using hash table for factors positions storing
// see Kociumaka, Radoszewski, Rytter, Walen:
// Efficient data structures for the factor periodicity problem.
// In Proc. of the Nineteenth Symposium on String Processing and Information Retrieval,
// volume 7608 of Lecture Notes in Computer Science, pages 284–294, section 5.1
class DBFHashTable : public DBF{
public:

    // type for arithmetic progression:
    // (first, last, diff)
    typedef array<int, 3> triplet;

    // default constructor
    DBFHashTable();

    // Creates a new DBF data structure and hash table
    // for constant-time succ and pred queries
    // it requires O(n log n) expected time and O(n log n) space
    DBFHashTable(const char * text, int n = -1);

    // Returns the first occurrence of
    // basic factor v having given id from range
    // [i - |v|, i]
    virtual int pred_short(int i, int k, int id);

    // Returns the first occurrence of
    // basic factor v having given id from range
    // [i, i + |v|]
    virtual int succ_short(int i, int k, int id);

private:
    typedef unordered_map<triplet, triplet> table_type;

    // fill positions data structure with
    // freshly-generated basic factor ids
    virtual void fill_positions(int k, int ids_count);

    // positions of basic factors
    table_type pos;

    // remove long SUCC and PREV queries from derived class
    using DBF::succ;
    using DBF::pred;

};

#endif  // DICTIONARY_OF_BASIC_FACTORS_H_
