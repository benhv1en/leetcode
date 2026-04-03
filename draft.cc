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
  vector<int> vec;
  vec.assign(1, 0);
  printf("%x\n", &vec[0]);
  cout << vec;
  printf("%x\n", vec.data());
  cout << vec;
}