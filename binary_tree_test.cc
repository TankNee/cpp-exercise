#include "binary_tree.h"
#include <gtest/gtest.h>

namespace binary_tree_execise {
TEST(BinaryTreeTest, Test1) {
  binary_tree_execise::binary_tree tree;
  EXPECT_EQ(tree.insert(5), 0);
  EXPECT_EQ(tree.insert(2), 0);
  EXPECT_EQ(tree.insert(7), 0);
  EXPECT_EQ(tree.insert(1), 0);
  EXPECT_EQ(tree.insert(3), 0);
  EXPECT_EQ(tree.insert(6), 0);
  EXPECT_EQ(tree.insert(8), 0);
}

TEST(BinaryTreeTest, Test2) {
  binary_tree_execise::binary_tree tree;
  EXPECT_EQ(tree.insert(5), 0);
  EXPECT_EQ(tree.insert(2), 0);
  EXPECT_EQ(tree.insert(7), 0);
  EXPECT_EQ(tree.insert(1), 0);

  EXPECT_EQ(tree.search(5), 0);
  EXPECT_EQ(tree.search(2), 0);
  EXPECT_EQ(tree.search(6), -1);
}
} // namespace binary_tree_execise

TEST(BinaryTreeTest, Test3) {
  binary_tree_execise::binary_tree tree;
  EXPECT_EQ(tree.insert(5), 0);
  EXPECT_EQ(tree.insert(2), 0);
  EXPECT_EQ(tree.insert(7), 0);
  EXPECT_EQ(tree.insert(1), 0);
  EXPECT_EQ(tree.insert(3), 0);

  // preorder traversal, catch the std output
  std::vector<int> pre_order_res;
  std::vector<int> pre_ground_truth{5, 2, 1, 3, 7};
  tree.preorder_traversal(tree.root_, pre_order_res);
  EXPECT_EQ(pre_order_res.size(), 5);
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(pre_order_res[i], pre_ground_truth[i]);
  }

  // inorder traversal, catch the std output
  std::vector<int> in_order_res;
  std::vector<int> in_ground_truth{1, 2, 3, 5, 7};
  tree.inorder_traversal(tree.root_, in_order_res);
  EXPECT_EQ(in_order_res.size(), 5);
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(in_order_res[i], in_ground_truth[i]);
  }

  // postorder traversal, catch the std output
  std::vector<int> post_order_res;
  std::vector<int> post_ground_truth{1, 3, 2, 7, 5};
  tree.postorder_traversal(tree.root_, post_order_res);
  EXPECT_EQ(post_order_res.size(), 5);
  for (int i = 0; i < 5; ++i) {
    EXPECT_EQ(post_order_res[i], post_ground_truth[i]);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}