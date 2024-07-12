# 定义编译器
CXX = g++

# 定义编译器选项
CXXFLAGS = -Wall -Wextra -O2

# 定义目标文件
TARGET = arr_test

# 定义源文件
SRC = arr_test.cpp

# 定义目标
all: $(TARGET)

# 编译目标文件
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# 清理生成的文件
clean:
	rm -f $(TARGET)

# 用于调试的打印信息
.PHONY: clean
