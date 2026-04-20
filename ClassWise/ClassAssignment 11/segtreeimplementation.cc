#include <iostream>
#include <stdexcept>
#include <vector>

class SegmentTree
{
public:
  explicit SegmentTree(const std::vector<int> &values)
      : n_(static_cast<int>(values.size())), tree_(4 * std::max(1, n_), 0)
  {
    if (n_ > 0)
    {
      build(values, 1, 0, n_ - 1);
    }
  }

  void update(int index, int value)
  {
    validate_index(index);
    update(1, 0, n_ - 1, index, value);
  }

  int query(int left, int right) const
  {
    if (n_ == 0)
    {
      throw std::out_of_range("Cannot query an empty segment tree.");
    }
    if (left < 0 || right < 0 || left > right || right >= n_)
    {
      throw std::out_of_range("Invalid query range.");
    }
    return query(1, 0, n_ - 1, left, right);
  }

private:
  int n_;
  std::vector<int> tree_;

  void validate_index(int index) const
  {
    if (n_ == 0 || index < 0 || index >= n_)
    {
      throw std::out_of_range("Index out of range.");
    }
  }

  void build(const std::vector<int> &values, int node, int start, int end)
  {
    if (start == end)
    {
      tree_[node] = values[start];
      return;
    }

    int mid = start + (end - start) / 2;
    int left_child = node * 2;
    int right_child = left_child + 1;

    build(values, left_child, start, mid);
    build(values, right_child, mid + 1, end);
    tree_[node] = tree_[left_child] + tree_[right_child];
  }

  void update(int node, int start, int end, int index, int value)
  {
    if (start == end)
    {
      tree_[node] = value;
      return;
    }

    int mid = start + (end - start) / 2;
    int left_child = node * 2;
    int right_child = left_child + 1;

    if (index <= mid)
    {
      update(left_child, start, mid, index, value);
    }
    else
    {
      update(right_child, mid + 1, end, index, value);
    }

    tree_[node] = tree_[left_child] + tree_[right_child];
  }

  int query(int node, int start, int end, int left, int right) const
  {
    if (left <= start && end <= right)
    {
      return tree_[node];
    }
    if (end < left || start > right)
    {
      return 0;
    }

    int mid = start + (end - start) / 2;
    int left_sum = query(node * 2, start, mid, left, right);
    int right_sum = query(node * 2 + 1, mid + 1, end, left, right);
    return left_sum + right_sum;
  }
};

int main()
{
  std::vector<int> values = {2, 1, 5, 3, 4};
  SegmentTree segment_tree(values);

  std::cout << "Sum of range [1, 3]: " << segment_tree.query(1, 3) << '\n';

  segment_tree.update(2, 10);
  std::cout << "After updating index 2 to 10\n";
  std::cout << "Sum of range [1, 3]: " << segment_tree.query(1, 3) << '\n';

  return 0;
}
