#include "binary_tree.h"
#include <iostream>

namespace binary_tree_execise {
int binary_tree::insert(int value) {
  // check root node is null
  if (root_ == nullptr) {
    this->root_ = new binary_tree_node(value, nullptr, nullptr);
  } else {
    binary_tree_node *current = root_;
    while (current != nullptr) {
      if (value < current->value) {
        if (current->left == nullptr) {
          binary_tree_node *node =
              new binary_tree_node(value, nullptr, nullptr);
          current->left = node;
          break;
        } else {
          current = current->left;
        }
      } else if (value > current->value) {
        // print left and right node
        if (current->right == nullptr) {
          binary_tree_node *node =
              new binary_tree_node(value, nullptr, nullptr);
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
}

int binary_tree::search(int value) {
  // 检查二叉树的根节点是否为空
  if (root_ == nullptr) {
    // 如果根节点为空，说明树为空，返回-1表示未找到
    return -1;
  } else {
    // 如果根节点不为空，从根节点开始搜索
    binary_tree_node *current = root_;
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
}

void binary_tree::preorder_traversal(binary_tree_node *root,
                                     std::vector<int> &res) {
  // 先输出根节点，如果存在的话
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
}

void binary_tree::inorder_traversal(binary_tree_node *root,
                                    std::vector<int> &res) {
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
}

void binary_tree::postorder_traversal(binary_tree_node *root,
                                      std::vector<int> &res) {
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
}

} // namespace binary_tree_execise

// int main() {
//   binary_tree_execise::binary_tree tree;
//   std::cout << "Inserting 10" << std::endl;
//   tree.insert(5);
//   std::cout << "Inserting 20" << std::endl;
//   tree.insert(2);
//   std::cout << "Inserting 5" << std::endl;
//   tree.insert(7);
//   std::cout << "Inserting 5 again!!" << std::endl;
//   tree.insert(1);
//   tree.insert(3);
//   std::vector<int> res;

//   std::cout << "Searching 10, Res: " << tree.search(10) << std::endl;
//   std::cout << "Searching 20, Res: " << tree.search(20) << std::endl;
//   std::cout << "Searching 5, Res: " << tree.search(5) << std::endl;
//   std::cout << "Searching 15, Res: " << tree.search(15) << std::endl;

//   std::cout << "Preorder Traversal: " << std::endl;
//   tree.preorder_traversal(tree.root_, res);
//   std::cout << std::endl;
//   std::cout << "Inorder Traversal: " << std::endl;
//   tree.inorder_traversal(tree.root_, res);
//   std::cout << std::endl;
//   std::cout << "Postorder Traversal: " << std::endl;
//   tree.postorder_traversal(tree.root_, res);
//   std::cout << std::endl;

//   return 0;
// }