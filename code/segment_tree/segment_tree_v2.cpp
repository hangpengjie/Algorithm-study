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

  SegmentTreeNode(int l, int r);
  SegmentTreeNode();
  void PushUp(SegmentTreeNode& l, SegmentTreeNode& r);
};

template <typename T>
SegmentTreeNode<T>::SegmentTreeNode(int l, int r) : left(l), right(r), lazy(0), sum(0), max_value(std::numeric_limits<T>::min()) {}

template <typename T>
SegmentTreeNode<T>::SegmentTreeNode() : left(0), right(0), lazy(0), sum(0), max_value(std::numeric_limits<T>::min()) {}

template <typename T>
void SegmentTreeNode<T>::PushUp(SegmentTreeNode& l, SegmentTreeNode& r) {
  this->sum = l.sum + r.sum;
  this->max_value = std::max(l.max_value, r.max_value);
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
    tr_[node] = SegmentTreeNode<T>(left, right);
    tr_[node].sum = a_[left];
    tr_[node].max_value = a_[left];
    tr_[node].lazy = 0;
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
    int mid = (tr_[node].left + tr_[node].right) >> 1;
    tr_[node * 2 + 1].sum += tr_[node].lazy * (mid - tr_[node].left + 1);
    tr_[node * 2 + 2].sum += tr_[node].lazy * (tr_[node].right - mid);
    tr_[node * 2 + 1].max_value += tr_[node].lazy;
    tr_[node * 2 + 2].max_value += tr_[node].lazy;
    tr_[node * 2 + 1].lazy += tr_[node].lazy;
    tr_[node * 2 + 2].lazy += tr_[node].lazy;
    tr_[node].lazy = 0;
  }
}

template <typename T>
void SegmentTree<T>::Update(int left, int right, T val) {
  Update(left, right, val, 0);
}

template <typename T>
void SegmentTree<T>::Update(int left, int right, T val, int node) {
  if (left <= tr_[node].left && tr_[node].right <= right) {
    tr_[node].sum += val * (tr_[node].right - tr_[node].left + 1);
    tr_[node].max_value += val;
    tr_[node].lazy += val;
    return;
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
    SegmentTreeNode<T> ans(left, right);
    if (left <= mid) {
      auto l = Query(left, right, node * 2 + 1);
      ans.PushUp(ans, l);
    }
    if (right > mid) {
      auto r = Query(left, right, node * 2 +  2);
      ans.PushUp(ans, r);
    }
    return ans;
  }
}


// END CUT

#endif  // SEGMENT_TREE_V2_CPP