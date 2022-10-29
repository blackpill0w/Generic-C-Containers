# Generic-C-Containers
Header only generic containers.
# Usage
- Vector:
```c
#include <stdio.h>
#include "vec.h"

// produces a type `vecSUFFIX` (SUFFIX should be specified to allow passing `struct something`)
vec_typedef(int, _int);

int main(void) {
  vec_int nums;
  vec_init(nums); // len: 0, capacity: 1
  vec_reserve(nums, 20); // reserve memory for 20 items; len: 0, capacity: 20
  
  vec_push(nums, 16); // len: 1, capacity: 20
  vec_push(nums, 30); // if max capacity is reached, double the memory is reserved
  
  printf("1st item: %d\n", vec_at(nums, 0)); // prints 16
  vec_at(nums, 0) = 12;
  printf("1st item: %d\n", vec_at(nums, 0)); // prints 12
  
  int i = vec_pop(nums); // pops last item
  // len: 1, capacity: 20
  printf("%d\n", i); // prints 30
  
  vec_pop(nums); // pops the last item
  vec_pop(nums); // trying to pop from empty vector, program aborts with an error message
  
  vec_at(nums, 9999) = 15; // trying to access out of bound memory, program aborts with an error message
  
  vec_free(nums); // free allocated resources
}
```

- Array:
```c
#include <stdio.h>
#include "arr.h"

// produces a type `arrSUFFIX` (SUFFIX should be specified to allow passing `struct something`)
arr_typedef(int, _int);

int main(void) {
  arr_int nums;
  arr_init(nums, 30); // produces an array of 30 elements (memory is 0 initialized)
  
  int i = arr_at(nums, 0); // i is 0
  
  arr_at(nums, 0) = 15;
  arr_at(nums, 6) = 13;
  
  arr_at(nums, 9999) = 15; // trying to access out of bound memory, program aborts with an error message
  
  arr_free(nums);
}
```

# Integration with a project
Just copy the .h files and `#include` them :]
# TODO
- [x] vector
- [x] array
- [ ] hashmap
