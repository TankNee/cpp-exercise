#include <iostream>
#include <vector>
namespace binary_tree_execise {

class binary_tree_node {
private:
  /* data */
public:
  int value;
  binary_tree_node *left;
  binary_tree_node *right;

  binary_tree_node(int value, binary_tree_node *left, binary_tree_node *right) {
    this->value = value;
    this->left = left;
    this->right = right;
  };
  ~binary_tree_node(){};
};

class binary_tree {
private:
public:
  binary_tree_node *root_;
  binary_tree() { root_ = nullptr; };
  ~binary_tree(){};

  int insert(int value);
  int search(int value);
  void preorder_traversal(binary_tree_node *root, std::vector<int> &res);
  void inorder_traversal(binary_tree_node *root, std::vector<int> &res);
  void postorder_traversal(binary_tree_node *root, std::vector<int> &res);
};

} // namespace binary_tree_execise
