#ifndef VECTOR_H
#define VECTOR_H
typedef struct Vector {
  int size;
  int* array;
} Vector;
void ConstructVector(Vector*);
void PushBackVector(Vector*, int);
#endif
#ifndef VECTOR_IMPLEMENTATION
#define VECTOR_IMPLEMENTATION
#include <malloc.h>
void ConstructVector(Vector* this_) {
  this_->size = 0;
  this_->array = (int*)malloc(sizeof(int));
}
void PushBackVector(Vector* this_, int element) {
  if (this_->size == 0) {
    ++this_->size;
    this_->array[0] = element;
  } else {
    ++this_->size;
    int* other_place = (int*)malloc(this_->size * sizeof(int));
    for (int i = 0; i < this_->size - 1; ++i) other_place[i] = this_->array[i];
    free(this_->array);
    this_->array = other_place;
    this_->array[this_->size - 1] = element;
  }
}
void PrintVector(Vector this_) {
  if (this_.size == 0)
    printf("[]");
  else {
    printf("[");
    for (int i = 0; i < this_.size; ++i) printf("%d, ", this_.array[i]);
    printf("\b\b]\n");
  }
}
#endif