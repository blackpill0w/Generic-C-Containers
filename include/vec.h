#ifndef _GENERIC_VECTOR_H
#define _GENERIC_VECTOR_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//! Define vector for the given type, the produced type is vecNAME_SUFFIX
#define vec_typedef(TYPE, NAME_SUFFIX)          \
   typedef struct {                             \
      unsigned int _len;                        \
      unsigned int _capacity;                   \
      TYPE *v;                                  \
   } vec##NAME_SUFFIX;


/*!
  \def vec_free(vec)
  Free allocated resources.
*/
#define vec_free(vec) free((vec).v)

//! Get vector's length.
#define vec_len(vec) (vec)._len

//! Get vector's capacity.
#define vec_capacity(vec) (vec)._capacity

//! Sets all bits to 0.
#define vec_init(vec) memset(&(vec), 0, sizeof(vec)); (vec).v = NULL

//! Insert an item into the vector.
#define vec_push(vec, item)                               \
   {                                                      \
      if ((vec)._len == (vec)._capacity) {                \
         (vec).v = realloc(                               \
            (vec).v,                                      \
            (vec)._capacity++ * sizeof((vec).v[0])        \
         );                                               \
      }                                                   \
      (vec).v[(vec)._len++] = item;                       \
   }

//! Get an item from the vector using an index, abort if the index is out of bound.
#define vec_get(vec, i) ({                                            \
   if (i > (vec)._capacity) {                                         \
      fprintf(stderr,                                                 \
              "\nError: accessing out of bound memory, aborting...\n" \
      );                                                              \
      abort();                                                        \
   }                                                                  \
   (vec).v[i];                                                        \
})

//! Remove the last item, and return it.
#define vec_pop(vec)  ({                                              \
   if ((vec)._len <= 0) {                                             \
      fprintf(stderr,                                                 \
              "\nError: accessing out of bound memory, aborting...\n" \
      );                                                              \
      abort();                                                        \
   }                                                                  \
   (vec).v[(vec)._len-- - 1];                                         \
})

/*!
   Increase the capacity of the vector.
   If n is less than the vector's capacity, no changes are made.
*/
#define vec_reserve(vec, n)                                    \
   if ((vec)._capacity < n) {                                  \
      (vec).v = realloc((vec).v, n * sizeof((vec).v[0]) );     \
      (vec)._capacity = n;                                     \
   }                                                           \

#endif // _GENERIC_VECTOR_H
