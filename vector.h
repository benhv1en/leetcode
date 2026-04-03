#ifndef VECTOR_H
#define VECTOR_H
typedef struct Vector {
  int size;
  int* array;
} Vector;
void Vector_Construct(Vector* this_);
void Vector_Destruct(Vector* this_);
void Vector_Print(Vector this_);
#endif
#ifndef VECTOR_IMPLEMENTATION
#define VECTOR_IMPLEMENTATION
#include <malloc.h>
void Vector_Construct(Vector* this_) {
  this_->size = 0;
  this_->array = (int*)malloc(sizeof(int));
}
void Vector_Destruct(Vector* this_) { free(this_->array); }
void Vector_Print(Vector this_) {
  printf("[");
  for (int i = 0; i < this_.size; ++i) printf("%d, ", this_.array[i]);
  printf("\b\b]\n");
}
void Vector_Assign(Vector* this_, int number, int time) {
  this_->size = time;
  int* other_place = (int*)malloc(time * sizeof(int));
  for (int i = 0; i < time; ++i) {
    other_place[i] = number;
  }
  this_->array = other_place;
};
#include <assert.h>
int Vector_At(Vector this_, int index) {
  assert(index >= 0);
  assert(index < this_.size);
  return this_.array[index];
}
int Vector_Back(Vector this_) { return this_.array[this_.size - 1]; }
int* Vector_Begin(Vector this_) { return &this_.array[0]; }
size_t Vector_Capacity(Vector this_) { return this_.size; }
const int* Vector_CBegin(Vector this_) { return &this_.array[0]; }
const int* Vector_CEnd(Vector this_) { return &this_.array[this_.size]; }
void Vector_Clear(Vector* this_) {
  this_->size = 0;
  free(this_->array);
  this_->array = (int*)malloc(sizeof(int));
}
const int* Vector_CRBegin(Vector this_) { return &this_.array[this_.size - 1]; }
const int* Vector_CREnd(Vector this_) { return &this_.array[-1]; }
int* Vector_Data(Vector this_) {
  assert(this_.size != 0);
  return &this_.array[0];
}
#include <stdarg.h>

#endif