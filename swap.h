#ifndef SWAP_H
#define SWAP_H
void Swap(int* a, int* b);
#endif
#ifndef SWAP_IMPLEMENTATION
#define SWAP_IMPLEMENTATION
void Swap(int* a, int* b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}
#endif