#ifndef ARRAY_H
#define ARRAY_H
typedef struct Array {
  unsigned long data;
  int* array;
} Array;
int Array_At(const Array this_, const unsigned long index);
int Array_Back(const Array this_);
int* Array_Begin(const Array this_);
const int* Array_CBegin(const Array this_);
const int* Array_CEnd(const Array this_);

#endif
#ifndef ARRAY_IMPLEMENTATION
#define ARRAY_IMPLEMENTATION
#endif