#include <stdio.h>

#include "vector.h"
int main() {
  Vector vec;
  Vector_Assign(&vec, 3, 3);
  Vector_Print(vec);
  const int* cit = Vector_CREnd(vec);
  printf("%x\n", cit);
  const int* cit2 = Vector_CBegin(vec);
  printf("%x\n", cit2);
}