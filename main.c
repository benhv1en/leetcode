#include <stdio.h>

#include "vector.h"
int main() {
  Vector vec;
  Vector_Assign(&vec, 3, 3);
  Vector_Print(vec);
  const int* cit = Vector_CREnd(vec);
  // printf("%x\n", cit);
  const int* cit2 = Vector_CBegin(vec);
  Vector_Assign(&vec, 4, 4);
  // printf("%x\n", cit2);
  Vector_Emplace(&vec, 2);
  Vector_Print(vec);
  Vector_EmplaceBack(&vec, 6);
  Vector_Print(vec);
  Vector_Erase(&vec, Vector_Begin(vec) + 5);
  Vector_Print(vec);
  // Vector_Destruct(&vec);
  Vector_Insert(&vec, Vector_Begin(vec) + 0, 10);
  Vector_Print(vec);
  Vector_PushBack(&vec, 123);
  Vector_PushBack(&vec, 456);
  Vector_PushBack(&vec, 789);
  Vector_PushBack(&vec, 101112);
  Vector_PushBack(&vec, 321);
  Vector_PushBack(&vec, 666);
  Vector_Print(vec);
  Vector_Reserve(&vec, 20);
  Vector_Print(vec);
  Vector_Resize(&vec, 2);
  Vector_Print(vec);
  Vector_Resize(&vec, 9);
  Vector_Print(vec);
  Vector_Destruct(&vec);

  Vector vec1, vec2;
  Vector_Construct(&vec1);
  Vector_Print(vec1);
  Vector_Construct(&vec2);
  Vector_Print(vec2);
  Vector_Assign(&vec1, 6, 9);
  Vector_Print(vec1);
  Vector_Assign(&vec2, 9, 6);
  Vector_Print(vec2);
  Vector_Swap(&vec1, &vec2);
  Vector_Print(vec1);
  Vector_Print(vec2);
}