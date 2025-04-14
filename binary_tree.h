// Copyright (c) 2025 Tencent Inc. All rights reserved.
//
// Author: tongkeni@tencent.com

#pragma once

#include <stack>
#include <vector>

namespace binary_tree_execise {

template <typename T>
class BinaryTreeNode {
 public:
  T value;
  BinaryTreeNode<T>* left;
  BinaryTreeNode<T>* right;

  explicit BinaryTreeNode(T value_, BinaryTreeNode<T>* left_ = nullptr, BinaryTreeNode<T>* right_ = nullptr)
      : value(value_), left(left_), right(right_) {}
  BinaryTreeNode(const BinaryTreeNode&) = default;
  BinaryTreeNode& operator=(const BinaryTreeNode&) = default;
  BinaryTreeNode(BinaryTreeNode&& other) noexcept = default;
  BinaryTreeNode& operator=(BinaryTreeNode&& other) noexcept = default;
  ~BinaryTreeNode() = default;
};

template <typename T>
class BinaryTree {
 public:
  BinaryTreeNode<T>* root_;
  BinaryTree() : root_(nullptr) {}
  BinaryTree& operator=(const BinaryTree&) = default;
  BinaryTree(BinaryTree&& other) noexcept = default;
  BinaryTree& operator=(BinaryTree&& other) noexcept = default;
  ~BinaryTree() = default;
  /**
   * @brief Insert a value into the binary tree
   * @param value The value to be inserted
   * @return true if the value is inserted successfully, false otherwise
   */
  [[nodiscard]] bool Insert(const T& value);
  /**
   * @brief Search a value in the binary tree
   * @param value The value to be searched
   * @return true if the value is found, false otherwise
   */
  [[nodiscard]] bool Search(const T& value);
  /**
   * @brief Remove a value from the binary tree
   * @param value The value to be removed
   * @return true if the value is removed successfully, false otherwise
   */
  [[nodiscard]] bool Remove(const T& value);
  /**
   * @brief Check if the binary tree is empty
   * @return true if the binary tree is empty, false otherwise
   */
  [[nodiscard]] bool IsEmpty();
  /**
   * @brief Get the size of the binary tree
   * @return The size of the binary tree
   */
  [[nodiscard]] size_t Size();
  /**
   * @brief Traverse the binary tree in preorder
   * @param results The vector to store the traversal results
   */
  void PreorderTraversal(std::vector<T>& results);
  /**
   * @brief Traverse the binary tree in inorder
   * @param results The vector to store the traversal results
   */
  void InorderTraversal(std::vector<T>& results);
  /**
   * @brief Traverse the binary tree in postorder
   * @param results The vector to store the traversal results
   */
  void PostorderTraversal(std::vector<T>& results);
};

template <typename T>
bool BinaryTree<T>::Insert(const T& value) {
  // check root node is null
  if (root_ == nullptr) {
    this->root_ = new BinaryTreeNode<T>(value, nullptr, nullptr);
  } else {
    BinaryTreeNode<T>* current = root_;
    while (current != nullptr) {
      if (value < current->value) {
        if (current->left == nullptr) {
          BinaryTreeNode<T>* node = new BinaryTreeNode<T>(value, nullptr, nullptr);
          current->left = node;
          break;
        } else {
          current = current->left;
        }
      } else if (value > current->value) {
        // print left and right node
        if (current->right == nullptr) {
          BinaryTreeNode<T>* node = new BinaryTreeNode<T>(value, nullptr, nullptr);
          current->right = node;
          break;
        } else {
          current = current->right;
        }
      } else {
        // Value already exists, No action taken
        return false;
      }
    }
  }
  return true;
}

template <typename T>
bool BinaryTree<T>::Search(const T& value) {
  if (root_ == nullptr) {
    return false;
  } else {
    BinaryTreeNode<T>* current = root_;
    // 使用循环遍历二叉树
    while (current != nullptr) {
      if (value < current->value) {
        current = current->left;
      } else if (value > current->value) {
        current = current->right;
      } else {
        return true;
      }
    }
    return false;
  }
}

template <typename T>
bool BinaryTree<T>::Remove(const T& value) {
  BinaryTreeNode<T>* current = root_;
  BinaryTreeNode<T>* parent = nullptr;
  bool is_left_child = false;

  // 查找要删除的节点及其父节点
  while (current != nullptr && current->value != value) {
    parent = current;
    if (value < current->value) {
      current = current->left;
      is_left_child = true;
    } else {
      current = current->right;
      is_left_child = false;
    }
  }

  // 如果没有找到要删除的节点
  if (current == nullptr) {
    return false;
  }

  // 情况1：要删除的节点是叶子节点
  if (current->left == nullptr && current->right == nullptr) {
    if (current == root_) {
      root_ = nullptr;
    } else if (is_left_child) {
      parent->left = nullptr;
    } else {
      parent->right = nullptr;
    }
    delete current;
  }
  // 情况2：要删除的节点有一个子节点
  else if (current->left == nullptr || current->right == nullptr) {
    BinaryTreeNode<T>* child = (current->left != nullptr) ? current->left : current->right;
    if (current == root_) {
      root_ = child;
    } else if (is_left_child) {
      parent->left = child;
    } else {
      parent->right = child;
    }
    delete current;
  }
  // 情况3：要删除的节点有两个子节点
  else {
    BinaryTreeNode<T>* successor = current->right;
    BinaryTreeNode<T>* successor_parent = current;

    // 找到右子树中的最小值节点
    while (successor->left != nullptr) {
      successor_parent = successor;
      successor = successor->left;
    }

    // 用后继节点的值替换要删除的节点的值
    current->value = successor->value;

    // 删除后继节点
    if (successor_parent->left == successor) {
      successor_parent->left = successor->right;
    } else {
      successor_parent->right = successor->right;
    }
    delete successor;
  }

  return true;
}

template <typename T>
bool BinaryTree<T>::IsEmpty() {
  return root_ == nullptr;
}

template <typename T>
size_t BinaryTree<T>::Size() {
  if (root_ == nullptr) {
    return 0;
  }
  size_t count = 0;
  std::stack<BinaryTreeNode<T>*> node_stack;
  node_stack.push(root_);
  while (!node_stack.empty()) {
    BinaryTreeNode<T>* node = node_stack.top();

    count += 1;
    node_stack.pop();

    if (node->right != nullptr) {
      node_stack.push(node->right);
    }
    if (node->left != nullptr) {
      node_stack.push(node->left);
    }
  }
  return count;
}

template <typename T>
void BinaryTree<T>::PreorderTraversal(std::vector<T>& results) {
  if (root_ == nullptr) {
    return;
  }
  std::stack<BinaryTreeNode<T>*> node_stack;
  node_stack.push(root_);
  while (!node_stack.empty()) {
    BinaryTreeNode<T>* node = node_stack.top();
    node_stack.pop();
    results.push_back(node->value);
    if (node->right != nullptr) {
      node_stack.push(node->right);
    }
    if (node->left != nullptr) {
      node_stack.push(node->left);
    }
  }
}

template <typename T>
void BinaryTree<T>::InorderTraversal(std::vector<T>& results) {
  if (root_ == nullptr) {
    return;
  }
  std::stack<BinaryTreeNode<T>*> node_stack;
  BinaryTreeNode<T>* current = root_;

  while (current != nullptr || !node_stack.empty()) {
    while (current != nullptr) {
      node_stack.push(current);
      current = current->left;
    }
    current = node_stack.top();
    node_stack.pop();
    results.push_back(current->value);
    current = current->right;
  }
}

template <typename T>
void BinaryTree<T>::PostorderTraversal(std::vector<T>& results) {
  if (root_ == nullptr) {
    return;
  }
  std::stack<BinaryTreeNode<T>*> node_stack;
  BinaryTreeNode<T>* last_visited = nullptr;
  BinaryTreeNode<T>* current = root_;
  while (!node_stack.empty() || current != nullptr) {
    if (current != nullptr) {
      // 先遍历左子树，直到最左节点
      node_stack.push(current);
      current = current->left;
    } else {
      // 当前节点为空，从栈中取出一个节点
      BinaryTreeNode<T>* peek_node = node_stack.top();
      if (peek_node->right != nullptr && peek_node->right != last_visited) {
        // 右子树存在且未被访问，继续遍历右子树
        current = peek_node->right;
      } else {
        // 右子树为空或已被访问，访问当前节点
        results.push_back(peek_node->value);
        last_visited = peek_node;
        node_stack.pop();
      }
    }
  }
}

}  // namespace binary_tree_execise
