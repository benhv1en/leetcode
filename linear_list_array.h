#ifndef LINEAR_LIST_ARRAY_H
#define LINEAR_LIST_ARRAY_H
typedef struct LinearListArray {
  int* array;
  int last;
} LinearListArray;
#endif
#ifndef LINEAR_LIST_ARRAY_IMPLEMENTATION
#define LINEAR_LIST_ARRAY_IMPLEMENTATION
#include <malloc.h>
LinearListArray CreateLinearListArray() {
  LinearListArray list;
  list.last = -1;
  list.array = (int*)malloc(sizeof(int));
  return list;
}
#include <assert.h>
void InsertToLinearListArray(int x, unsigned p, LinearListArray* L) {
  assert(p >= 0);
  assert(p <= L->last + 1);
  ++L->last;
  int* other_place = (int*)malloc((L->last + 1) * sizeof(int));
  for (int i = 0; i < p; ++i) other_place[i] = L->array[i];
  other_place[p] = x;
  for (int i = p + 1; i <= L->last; ++i) other_place[i] = L->array[i - 1];
  free(L->array);
  L->array = other_place;
}
unsigned LocateLinearListArray(int x, LinearListArray L) {
  int index = 0;
  while ((L.array[index] != x) && (index <= L.last)) ++index;
  return index;
}
int RetrieveLinearListArray(unsigned p, LinearListArray L) {
  assert(p >= 0);
  assert(p <= L.last);
  return L.array[p];
}
#ifndef SWAP
#define SWAP
void Swap(int* a, int* b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}
#endif
void DeleteInLinearListArray(unsigned p, LinearListArray* L) {
  assert(p >= 0);
  assert(p <= L->last);
  --L->last;
  for (int i = p; i <= L->last; ++i) Swap(&L->array[i], &L->array[i + 1]);
}
int NextOfInLinearListArray(unsigned p, LinearListArray L) {}
int PreviousOfInLinearListArray(unsigned p, LinearListArray L) {}
void MakeNullLinearListArray(LinearListArray* L) {}
int FirstOfLinearListArray(LinearListArray L) {}
void PrintLinearListArray(LinearListArray L) {
  printf("[");
  for (int i = 0; i <= L.last; ++i) printf("%d, ", L.array[i]);
  printf("\b\b]\n");
}
#endif