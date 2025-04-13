#include <iostream>
#include <vector>

namespace binary_tree_tmp_execise {

template <typename T> class binary_tree_node {
private:
  /* data */
public:
  T value;
  binary_tree_node *left;
  binary_tree_node *right;

  binary_tree_node(T value, binary_tree_node *left, binary_tree_node *right) {
    this->value = value;
    this->left = left;
    this->right = right;
  };
  ~binary_tree_node(){};
};

template <typename T> class binary_tree {
private:
public:
  binary_tree_node<T> *root_;
  binary_tree() { root_ = nullptr; };
  ~binary_tree(){};

  int insert(T value) {
    // check root node is null
    if (root_ == nullptr) {
      this->root_ = new binary_tree_node<T>(value, nullptr, nullptr);
    } else {
      binary_tree_node<T> *current = root_;
      while (current != nullptr) {
        if (value < current->value) {
          if (current->left == nullptr) {
            binary_tree_node<T> *node =
                new binary_tree_node<T>(value, nullptr, nullptr);
            current->left = node;
            break;
          } else {
            current = current->left;
          }
        } else if (value > current->value) {
          // print left and right node
          if (current->right == nullptr) {
            binary_tree_node<T> *node =
                new binary_tree_node<T>(value, nullptr, nullptr);
            current->right = node;
            break;
          } else {
            current = current->right;
          }
        } else {
          std::cout << "Value already exists, No action taken" << std::endl;
          return -1;
        }
      }
    }
    return 0;
  };
  int search(T value) {
    // 检查二叉树的根节点是否为空
    if (root_ == nullptr) {
      // 如果根节点为空，说明树为空，返回-1表示未找到
      return -1;
    } else {
      // 如果根节点不为空，从根节点开始搜索
      binary_tree_node<T> *current = root_;
      // 使用循环遍历二叉树
      while (current != nullptr) {
        // 如果当前节点的值大于要搜索的值，向左子树搜索
        if (value < current->value) {
          current = current->left;
          // 如果当前节点的值小于要搜索的值，向右子树搜索
        } else if (value > current->value) {
          current = current->right;
          // 如果当前节点的值等于要搜索的值，返回0表示找到
        } else {
          return 0;
        }
      }
      // 如果遍历完整个树都没有找到，返回-1表示未找到
      return -1;
    }
  };
  void preorder_traversal(binary_tree_node<T> *root,
                          std::vector<T> &res) { // 先输出根节点，如果存在的话
    if (root != nullptr) {
      res.push_back(root->value);
      // 递归调用左子树
      preorder_traversal(root->left, res);
      // 递归调用右子树
      preorder_traversal(root->right, res);
    } else {
      // 如果根节点为空，什么都不做
      return;
    }
  };
  void inorder_traversal(binary_tree_node<T> *root, std::vector<T> &res) {
    // 先输出左子树，如果存在的话
    if (root != nullptr) {
      // 递归调用左子树
      inorder_traversal(root->left, res);
      res.push_back(root->value);
      // 递归调用右子树
      inorder_traversal(root->right, res);
    } else {
      // 如果根节点为空，什么都不做
      return;
    }
  };
  void postorder_traversal(binary_tree_node<T> *root, std::vector<T> &res) {
    // 先输出左子树，如果存在的话
    if (root != nullptr) {
      // 递归调用左子树
      postorder_traversal(root->left, res);
      // 递归调用右子树
      postorder_traversal(root->right, res);
      res.push_back(root->value);
    } else {
      // 如果根节点为空，什么都不做
      return;
    }
  };
};

} // namespace binary_tree_tmp_execise
