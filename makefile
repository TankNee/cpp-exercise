# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -std=c++17 -g

# 链接选项
LDFLAGS = -lstdc++ -lgtest -lgtest_main -lm

# 源文件
SRCS = binary_tree.cc binary_tree_test.cc

# 目标文件
OBJS = $(SRCS:.cc=.o)

# 可执行文件
TARGET = binary_tree_test

# 默认目标
all: $(TARGET)

BINARY_SRCS = binary_tree_template_test.cc
TEMP_TARGET = binary_tree_temp
$(TEMP_TARGET): $(BINARY_SRCS:.cc=.o)
	$(CXX) $(BINARY_SRCS:.cc=.o) -o $@ $(LDFLAGS)

# 链接可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# 编译源文件
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(OBJS) $(TARGET) $(TEMP_TARGET) $(BINARY_SRCS:.cc=.o)
