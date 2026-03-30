#include <stdio.h>

#include "vector.h"
int main() {
  Vector vector;
  ConstructVector(&vector);
  PushBackVector(&vector, 2);
  PushBackVector(&vector, 5);
  PrintVector(vector);
}