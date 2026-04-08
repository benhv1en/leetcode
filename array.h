#ifndef ARRAY_H
#define ARRAY_H
typedef struct Array {
  unsigned long size;
  int* array;
} Array;
void Array_Construct(Array* this_);
void Array_Destruct(Array* this_);
int Array_At(const Array this_, const unsigned long index);
int Array_Back(const Array this_);
int* Array_Begin(const Array this_);
const int* Array_CBegin(const Array this_);
const int* Array_CEnd(const Array this_);
const int* Array_CRBegin(const Array this_);
const int* Array_CREnd(const Array this_);
int* Array_Data(const Array this_);
#include <stdbool.h>
bool Array_Empty(const Array this_);
int* Array_End(const Array this_);
#endif
#ifndef ARRAY_IMPLEMENTATION
#define ARRAY_IMPLEMENTATION
#include <assert.h>
#include <malloc.h>
void Array_Construct(Array* this_, const unsigned long size) {
  this_->size = size;
  this_->array = (int*)malloc(this_->size * sizeof(int));
  assert(this_->array != NULL);
}
void Array_Destruct(Array* this_) { free(this_->array); }
int Array_At(const Array this_, const unsigned long index) {
  return this_.array[index];
}
int Array_Back(const Array this_) { return this_.array[this_.size - 1]; }
int* Array_Begin(const Array this_) { return &this_.array[0]; }
int* Array_End(const Array this_) { return &this_.array[this_.size]; }
const int* Array_CBegin(const Array this_) { return &this_.array[0]; }
const int* Array_CEnd(const Array this_) { return &this_.array[this_.size]; }
const int* Array_CRBegin(const Array this_) {
  return &this_.array[this_.size - 1];
}
const int* Array_CREnd(const Array this_) { return &this_.array[-1]; }
void Array_Clear(Array* this_) {
  for (int i = 0; i < this_->size; ++i) this_->array[i] = 0;
}
#endif