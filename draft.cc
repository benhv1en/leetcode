#include <array>
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
ostream& operator<<(ostream& out_stream, vector<T> vector_) {
  out_stream << "[";
  for (const T& element : vector_) out_stream << element << ", ";
  if (vector_.size() == 0)
    out_stream << "]\n";
  else
    out_stream << "\b\b]\n";
  return out_stream;
}
int main() {
  array<int, 3> arr;
  arr.at(4);
  arr.back();
  arr.begin();
  arr.cbegin();
  arr.fill
}