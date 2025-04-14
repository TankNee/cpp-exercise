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
  EXPECT_TRUE(tree_.Insert(5));
  EXPECT_TRUE(tree_.Insert(2));
  EXPECT_TRUE(tree_.Insert(7));
  EXPECT_TRUE(tree_.Insert(1));
  EXPECT_TRUE(tree_.Insert(6));
  EXPECT_TRUE(tree_.Insert(3));
  EXPECT_EQ(tree_.Size(), 6);
  EXPECT_FALSE(tree_.IsEmpty());

  EXPECT_TRUE(tree_.Remove(2));
  EXPECT_FALSE(tree_.Search(2));
  EXPECT_FALSE(tree_.Remove(2));
  EXPECT_EQ(tree_.Size(), 5);
  EXPECT_TRUE(tree_.Insert(2));

  EXPECT_TRUE(tree_.Remove(1));
  std::vector<int64_t> pre_order_res;
  std::vector<int64_t> pre_ground_truth{5, 3, 2, 7, 6};
  tree_.PreorderTraversal(pre_order_res);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(pre_order_res[i], pre_ground_truth[i]);
  }

  EXPECT_TRUE(tree_.Remove(5));
  pre_order_res.clear();
  std::vector<int64_t> pre_ground_truth_after_remove{6, 3, 2, 7};
  tree_.PreorderTraversal(pre_order_res);
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_EQ(pre_order_res[i], pre_ground_truth_after_remove[i]);
  }
  EXPECT_EQ(tree_.Size(), 4);

  EXPECT_FALSE(tree_.Remove(1));
}

TEST_F(BinaryTreeTest, TraversalTest) {
  EXPECT_TRUE(tree_.Insert(5));
  EXPECT_TRUE(tree_.Insert(2));
  EXPECT_TRUE(tree_.Insert(7));
  EXPECT_TRUE(tree_.Insert(1));
  EXPECT_TRUE(tree_.Insert(3));

  // preorder traversal, catch the std output
  std::vector<int64_t> traversal_results;
  std::vector<int64_t> pre_ground_truth{5, 2, 1, 3, 7};
  tree_.PreorderTraversal(traversal_results);
  EXPECT_EQ(traversal_results.size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(traversal_results[i], pre_ground_truth[i]);
  }
  traversal_results.clear();

  // inorder traversal, catch the std output
  std::vector<int64_t> in_ground_truth{1, 2, 3, 5, 7};
  tree_.InorderTraversal(traversal_results);
  EXPECT_EQ(traversal_results.size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(traversal_results[i], in_ground_truth[i]);
  }
  traversal_results.clear();

  // postorder traversal, catch the std output
  std::vector<size_t> post_ground_truth{1, 3, 2, 7, 5};
  tree_.PostorderTraversal(traversal_results);
  EXPECT_EQ(traversal_results.size(), 5);
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(traversal_results[i], post_ground_truth[i]);
  }
}

}  // namespace binary_tree__execise

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}