#include <stdio.h>

#include "linear_list_array.h"
int main() {
  LinearListArray list;
  list = CreateLinearListArray();
  InsertToLinearListArray(2, 0, &list);
  InsertToLinearListArray(8, 0, &list);
  InsertToLinearListArray(4, 1, &list);
  InsertToLinearListArray(5, 3, &list);
  PrintLinearListArray(list);
  DeleteInLinearListArray(2, &list);
  PrintLinearListArray(list);
  InsertToLinearListArray(7, 3, &list);
  PrintLinearListArray(list);
}