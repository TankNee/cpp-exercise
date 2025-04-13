# 项目名称：cpp-exercise

## 简介

这是一个C++练习项目，包含了二叉树的数据结构和相关测试。项目使用了Google Test框架进行单元测试。

## 项目结构

项目的主要文件和目录结构如下：

- `binary_tree.h`：二叉树的数据结构定义。
- `binary_tree_template.h`：二叉树的模板类定义。
- `thirdpart/googletest`：Google Test框架的源代码。
- `thirdpart/googletest/googletest`：Google Test的主要代码。
- `thirdpart/googletest/googlemock`：Google Mock的主要代码。
- `thirdpart/googletest/googletest/include/gtest/internal/custom/README.md`：Google Test的自定义点说明。

## 如何使用

1. 克隆项目到本地。

2. 在项目根目录下创建一个build目录，并进入该目录。

3. 运行`make all` 或者 `make binary_tree_temp` 命令编译项目。

4. 运行`./binary_tree_test`命令运行测试。

## Google Test

Google Test是Google的C++测试框架，它提供了一个易于使用的接口来编写和运行测试。在这个项目中，我们使用Google Test来测试二叉树的数据结构和相关功能。

### 如何编写测试

在`binary_tree_test.cc`文件中，你可以编写测试来验证二叉树的功能。例如，你可以创建一个二叉树，然后添加一些节点，最后检查树的结构是否符合预期。

```cpp
#include "binary_tree.h"
#include <gtest/gtest.h>

TEST(BinaryTreeTest, InsertAndFind) {
    BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    EXPECT_TRUE(tree.find(1));
    EXPECT_TRUE(tree.find(2));
    EXPECT_TRUE(tree.find(3));
    EXPECT_FALSE(tree.find(4));
}
```

### 如何运行测试

在项目根目录下，运行`make test`命令来编译并运行所有的测试。

## 贡献

如果你有任何改进意见或者想要贡献代码，欢迎提交Pull Request或者创建Issue。


## 免责声明

请注意，这个项目是一个练习项目，可能不适合用于生产环境。