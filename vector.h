#ifndef VECTOR_H
#define VECTOR_H
typedef struct Vector {
  int size;
  int* array;
} Vector;
void Vector_Construct(Vector* this_);
void Vector_Destruct(Vector* this_);
void Vector_Print(const Vector this_);
#endif
#ifndef VECTOR_IMPLEMENTATION
#define VECTOR_IMPLEMENTATION
#include <malloc.h>
void Vector_Construct(Vector* this_) {
  this_->size = 0;
  this_->array = (int*)malloc(sizeof(int));
}
void Vector_Destruct(Vector* this_) { free(this_->array); }
void Vector_Print(const Vector this_) {
  printf("[");
  for (int i = 0; i < this_.size; ++i) printf("%d, ", this_.array[i]);
  if (this_.size == 0)
    printf("]\n");
  else
    printf("\b\b]\n");
}
void Vector_Assign(Vector* this_, const int number, const int time) {
  if (this_->size != 0) free(this_->array);
  this_->size = time;
  int* other_place = (int*)malloc(time * sizeof(int));
  for (int i = 0; i < time; ++i) {
    other_place[i] = number;
  }
  this_->array = other_place;
};
#include <assert.h>
int Vector_At(const Vector this_, const int index) {
  assert(index >= 0);
  assert(index < this_.size);
  return this_.array[index];
}
int Vector_Back(const Vector this_) { return this_.array[this_.size - 1]; }
int* Vector_Begin(const Vector this_) { return &this_.array[0]; }
size_t Vector_Capacity(const Vector this_) { return this_.size; }
const int* Vector_CBegin(const Vector this_) { return &this_.array[0]; }
const int* Vector_CEnd(const Vector this_) { return &this_.array[this_.size]; }
void Vector_Clear(Vector* this_) {
  this_->size = 0;
  free(this_->array);
  this_->array = (int*)malloc(sizeof(int));
}
const int* Vector_CRBegin(const Vector this_) {
  return &this_.array[this_.size - 1];
}
const int* Vector_CREnd(const Vector this_) { return &this_.array[-1]; }
int* Vector_Data(const Vector this_) {
  assert(this_.size != 0);
  return &this_.array[0];
}
void Vector_Emplace(Vector* this_, const int data) {
  ++this_->size;
  int* other_place = (int*)malloc(this_->size * sizeof(int));
  other_place[0] = data;
  for (int i = 1; i < this_->size; ++i) other_place[i] = this_->array[i - 1];
  free(this_->array);
  this_->array = other_place;
}
void Vector_EmplaceBack(Vector* this_, const int data) {
  int* other_place = (int*)malloc((this_->size + 1) * sizeof(int));
  for (int i = 0; i < this_->size; ++i) other_place[i] = this_->array[i];
  other_place[this_->size] = data;
  free(this_->array);
  this_->array = other_place;
  ++this_->size;
}
#include <stdbool.h>
bool Vector_Empty(const Vector this_) { return this_.size == 0; }
int* Vector_End(const Vector this_) { return &this_.array[this_.size]; }
#include "swap.h"
void Vector_Erase(Vector* this_, int* position) {
  assert(position >= &this_->array[0]);
  assert(position < &this_->array[this_->size]);
  for (int* i = position; i < &this_->array[this_->size - 1]; ++i)
    Swap(i, i + 1);
  --this_->size;
}
int Vector_Front(const Vector this_) { return this_.array[0]; }
void Vector_Insert(Vector* this_, const int* position, const int data) {
  assert(position >= &this_->array[0]);
  assert(position < &this_->array[this_->size]);
  ++this_->size;
  int* other_place = (int*)malloc(this_->size * sizeof(int));
  int index = 0;
  for (int* i = &this_->array[0]; i < position; ++i, ++index) {
    printf("other_place: %x\nposition: %x\n", other_place, position);
    other_place[index] = *i;
  }
  other_place[index] = data;
  for (int i = index + 1; i < this_->size; ++i)
    other_place[i] = this_->array[i - 1];
  free(this_->array);
  this_->array = other_place;
}
void Vector_PopBack(Vector* this_) { --this_->size; }
void Vector_PushBack(Vector* this_, const int data) {
  ++this_->size;
  int* other_place = (int*)malloc(this_->size * sizeof(int));
  for (int i = 0; i < this_->size - 1; ++i) other_place[i] = this_->array[i];
  other_place[this_->size - 1] = data;
  free(this_->array);
  this_->array = other_place;
}
int* Vector_RBegin(const Vector this_) { return &this_.array[this_.size - 1]; }
int* Vector_REnd(const Vector this_) { return &this_.array[-1]; }
void Vector_Reserve(Vector* this_, const int capacity) {
  if (capacity <= this_->size) return;
  int* other_place = (int*)malloc(capacity * sizeof(int));
  for (int i = 0; i < this_->size; ++i) other_place[i] = this_->array[i];
  free(this_->array);
  this_->array = other_place;
  this_->size = capacity;
}
void Vector_Resize(Vector* this_, const int size) {
  int* other_place = (int*)malloc(size * sizeof(int));
  if (size > this_->size) {
    for (int i = 0; i < this_->size; ++i) other_place[i] = this_->array[i];
    for (int i = this_->size; i < size; ++i) other_place[i] = 0;
  } else
    for (int i = 0; i < size; ++i) other_place[i] = this_->array[i];
  free(this_->array);
  this_->array = other_place;
  this_->size = size;
}
void Vector_ShrinkToFit(Vector* this_, const int capacity) {
  if (capacity >= this_->size) return;
  int* other_place = (int*)malloc(capacity * sizeof(int));
  for (int i = 0; i < capacity; ++i) other_place[i] = this_->array[i];
  free(this_->array);
  this_->array = other_place;
  this_->size = capacity;
}
size_t Vector_Size(const Vector this_) { return this_.size; }
void Vector_Swap(Vector* this_, Vector* other) {
  int* temporary = this_->array;
  this_->array = other->array;
  other->array = temporary;
  Swap(&this_->size, &other->size);
}
#endif