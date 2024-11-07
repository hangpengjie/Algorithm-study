#ifndef SEGMENT_TREE_V2_CPP
#define SEGMENT_TREE_V2_CPP


// START CUT
#include <vector>
#include <limits>

template <typename T>
class SegmentTreeNode {
 public:
  int left, right;
  T lazy, sum, max_value;
  SegmentTreeNode();
  void PushUp(const SegmentTreeNode& l, const SegmentTreeNode& r);
  void PushDown(SegmentTreeNode& l, SegmentTreeNode& r);
  void Update(T val);
};


template <typename T>
SegmentTreeNode<T>::SegmentTreeNode() : left(0), right(0), lazy(0), sum(0), max_value(0) {}

template <typename T>
void SegmentTreeNode<T>::PushUp(const SegmentTreeNode& l, const SegmentTreeNode& r) {
  this->sum = l.sum + r.sum;
  this->max_value = std::max(l.max_value, r.max_value);
}

template <typename T>
void SegmentTreeNode<T>::PushDown(SegmentTreeNode<T>& l, SegmentTreeNode<T>& r) {
  int mid = (this->left + this->right) >> 1;
  l.sum += this->lazy * (mid - this->left + 1);
  r.sum += this->lazy * (this->right - mid);
  l.max_value += this->lazy;
  r.max_value += this->lazy;
  l.lazy += this->lazy;
  r.lazy += this->lazy;
  this->lazy = 0;
}

template <typename T>
void SegmentTreeNode<T>::Update(T val) {
  this->sum += val * (this->right - this->left + 1);
  this->max_value += val;
  this->lazy += val;
}

template <typename T>
class SegmentTree {
 public:
  explicit SegmentTree(int n);
  explicit SegmentTree(const std::vector<T>& a);
  void Update(int left, int right, T val);
  SegmentTreeNode<T> Query(int left, int right);

 private:
  std::vector<SegmentTreeNode<T>> tr_;
  std::vector<T> a_;
  int n_;

  void Build(int left, int right, int node);
  void PushUp(int node);
  void PushDown(int node);
  void Update(int left, int right, T val, int node);
  SegmentTreeNode<T> Query(int left, int right, int node);
};

template <typename T>
SegmentTree<T>::SegmentTree(int n) : n_(n), tr_(n * 4), a_(n) {
  Build(0, n_ - 1, 0);
}

template <typename T>
SegmentTree<T>::SegmentTree(const std::vector<T>& a) : a_(a), n_(a.size()), tr_(a.size()* 4) {
  Build(0, n_ - 1, 0);
}

template <typename T>
void SegmentTree<T>::Build(int left, int right, int node) {
  if (left == right) {
    tr_[node].left = left;
    tr_[node].right = right;
    tr_[node].Update(a_[left]);
  } else {
    tr_[node].left = left;
    tr_[node].right = right;

    int mid = (left + right) >> 1;
    Build(left, mid, node * 2 + 1);
    Build(mid + 1, right, node * 2 + 2);
    PushUp(node);
  }
}

template <typename T>
void SegmentTree<T>::PushUp(int node) {
  tr_[node].PushUp(tr_[node * 2 + 1], tr_[node * 2 + 2]);
}

template <typename T>
void SegmentTree<T>::PushDown(int node) {
  if (tr_[node].lazy) {
    tr_[node].PushDown(tr_[node * 2 + 1], tr_[node * 2 + 2]);
  }
}

template <typename T>
void SegmentTree<T>::Update(int left, int right, T val) {
  Update(left, right, val, 0);
}

template <typename T>
void SegmentTree<T>::Update(int left, int right, T val, int node) {
  if (left <= tr_[node].left && tr_[node].right <= right) {
    tr_[node].Update(val);
  } else {
    PushDown(node);
    int mid = (tr_[node].left + tr_[node].right) >> 1;
    if (left <= mid) {
      Update(left, right, val, node * 2 + 1);
    }
    if (right > mid) {
      Update(left, right, val, node * 2 +  2);
    }
    PushUp(node);
  }
}


template <typename T>
SegmentTreeNode<T> SegmentTree<T>::Query(int left, int right) {
  return Query(left, right, 0);
}

template <typename T>
SegmentTreeNode<T> SegmentTree<T>::Query(int left, int right, int node) {
  if (left <= tr_[node].left && tr_[node].right <= right) {
    return tr_[node];
  } else {
    PushDown(node);
    int mid = (tr_[node].left + tr_[node].right) >> 1;
    SegmentTreeNode<T> ans;
    ans.left = left;
    ans.right = right;
    if (left <= mid) {
      ans.PushUp(ans, Query(left, right, node * 2 + 1));
    }
    if (right > mid) {
      ans.PushUp(ans, Query(left, right, node * 2 +  2));
    }
    return ans;
  }
}


// END CUT

#endif  // SEGMENT_TREE_V2_CPP