#ifndef FENWICK_TREE_V2_H
#define FENWICK_TREE_V2_H


// START CUT
#include <vector>
#include <type_traits>

template <typename T>
class FenwickTree {
  static_assert(std::is_integral<T>::value || std::is_arithmetic<T>::value, "T must be an integer type");

 private:
  int Lowbit(int x);
  std::vector<T> c_;  // c_[i] is the sum of the elements in [i - Lowbit(i) + 1, i]

 public:
  explicit FenwickTree(size_t n);
  ~FenwickTree();

  T Ask(int x);  // Ask the sum of the elements in [1, x]
  void Add(int x, T v);  // Add v to the element at index x
  void Update(int x, T v);  // Update the element at index x
};

template <typename T>
FenwickTree<T>::FenwickTree(size_t n) : c_(n + 1) {}

template <typename T>
FenwickTree<T>::~FenwickTree() {
  c_.clear();
}

template <typename T>
int FenwickTree<T>::Lowbit(int x) {
  return x & (-x);
}

template <typename T>
T FenwickTree<T>::Ask(int x) {
  T ans = 0;
  while (x > 0) {
    ans += c_[x];
    x -= Lowbit(x);
  }
  return ans;
}

template <typename T>
void FenwickTree<T>::Add(int x, T v) {
  while (x < c_.size()) {
    c_[x] += v;
    x += Lowbit(x);
  }
}

template <typename T>
void FenwickTree<T>::Update(int x, T v) {
  T pre = Ask(x) - Ask(x - 1);
  Add(x, v - pre);
}

// END CUT

#endif