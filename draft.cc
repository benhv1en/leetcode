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
  vector<int> vec;
  vec.assign(4, 5);
  printf("%x\n", &vec[0]);
  cout << vec;
  printf("%x\n", vec.data());
  cout << vec;
  vec.emplace(vec.begin(), 4);
  cout << vec;
  vec = {1, 2, 3, 4, 5, 6};
  vec.erase(vec.begin() + 3);
  cout << vec.insert();
}