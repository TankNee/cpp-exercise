// Copyright (c) 2025 Tencent Inc. All rights reserved.
//
// Author: tongkeni@tencent.com

#include "binary_tree.h"
#include <gtest/gtest.h>

namespace binary_tree_execise {

class BinaryTreeTest : public ::testing::Test {
 protected:
  BinaryTree<int64_t> tree_;
};

TEST_F(BinaryTreeTest, ActionTest) {
  EXPECT_TRUE(tree_.IsEmpty());
  EXPECT_TRUE(tree_.Emplace(5));
  EXPECT_TRUE(tree_.Emplace(2));
  EXPECT_TRUE(tree_.Emplace(7));
  EXPECT_TRUE(tree_.Emplace(1));
  BinaryTreeNode<int64_t> insert_node(6, nullptr, nullptr);
  EXPECT_TRUE(tree_.Insert(insert_node));
  EXPECT_TRUE(tree_.Emplace(3));
  EXPECT_EQ(tree_.Size(), 6);
  EXPECT_FALSE(tree_.IsEmpty());

  EXPECT_TRUE(tree_.Remove(2));
  EXPECT_FALSE(tree_.IsExist(2));
  EXPECT_FALSE(tree_.Remove(2));
  EXPECT_EQ(tree_.Size(), 5);
  EXPECT_TRUE(tree_.Emplace(2));

  const BinaryTreeNode<int64_t> remove_node1(1, nullptr, nullptr);
  EXPECT_TRUE(tree_.Remove(remove_node1));
  std::vector<int64_t> pre_order_res = tree_.PreorderTraversal();
  std::vector<int64_t> pre_ground_truth = {5, 3, 2, 7, 6};
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(pre_order_res[i], pre_ground_truth[i]);
  }

  const BinaryTreeNode<int64_t>* remove_node2 = tree_.root_;
  EXPECT_TRUE(tree_.Remove(remove_node2));
  pre_order_res.clear();
  pre_order_res = tree_.PreorderTraversal();
  std::vector<int64_t> pre_ground_truth_after_remove = {6, 3, 2, 7};
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_EQ(pre_order_res[i], pre_ground_truth_after_remove[i]);
  }
  EXPECT_EQ(tree_.Size(), 4);

  EXPECT_FALSE(tree_.Remove(1));
}

TEST_F(BinaryTreeTest, TraversalTest) {
  EXPECT_TRUE(tree_.Emplace(5));
  EXPECT_TRUE(tree_.Emplace(2));
  EXPECT_TRUE(tree_.Emplace(7));
  EXPECT_TRUE(tree_.Emplace(1));
  EXPECT_TRUE(tree_.Emplace(3));

  std::vector<int64_t> traversal_results;
  std::vector<int64_t> pre_ground_truth = {5, 2, 1, 3, 7};
  traversal_results = tree_.PreorderTraversal();
  EXPECT_EQ(traversal_results.size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(traversal_results[i], pre_ground_truth[i]);
  }
  traversal_results.clear();

  // inorder traversal, catch the std output
  std::vector<int64_t> in_ground_truth = {1, 2, 3, 5, 7};
  traversal_results = tree_.InorderTraversal();
  EXPECT_EQ(traversal_results.size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(traversal_results[i], in_ground_truth[i]);
  }
  traversal_results.clear();

  // postorder traversal, catch the std output
  std::vector<size_t> post_ground_truth = {1, 3, 2, 7, 5};
  traversal_results = tree_.PostorderTraversal();
  EXPECT_EQ(traversal_results.size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(traversal_results[i], post_ground_truth[i]);
  }
}

}  // namespace binary_tree_execise

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}