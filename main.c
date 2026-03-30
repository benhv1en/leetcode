#include <stdio.h>

#include "vector.h"
int main() {
  Vector vec;
  ConstructVector(&vec);
  PushBackVector(&vec, 2);
  PushBackVector(&vec, 5);
  PrintVector(vec);
}