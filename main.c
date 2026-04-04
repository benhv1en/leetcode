#include <stdio.h>

#include "vector.h"
int main() {
  Vector vec;
  Vector_Assign(&vec, 3, 3);
  Vector_Print(vec);
  const int* cit = Vector_CREnd(vec);
  printf("%x\n", cit);
  const int* cit2 = Vector_CBegin(vec);
  Vector_Assign(&vec, 4, 4);
  printf("%x\n", cit2);
  Vector_Emplace(&vec, 2);
  Vector_Print(vec);
  Vector_EmplaceBack(&vec, 6);
  Vector_Print(vec);
  Vector_Erase(&vec, Vector_Begin(vec) + 5);
  Vector_Print(vec);
  // Vector_Destruct(&vec);
  Vector_Insert(&vec, Vector_Begin(vec) + 3, 10);
  Vector_Print(vec);
}