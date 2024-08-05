
# M1芯片 Mac编译C++代码

要在M1芯片 Mac上编译这个C++代码，你可以使用`g++`编译器。以下是具体步骤：

1. 打开终端。
2. 导航到包含[`page_15.cpp`](./page_15.cpp)文件的目录。
3. 使用以下命令编译代码：

```sh
g++ -o page_15 page_15.cpp
```

4. 编译成功后，运行生成的可执行文件：

```sh
./page_15
```


# Apple Clang是什么
Apple Clang 是 Apple 提供的 Clang 编译器的一个版本。Clang 是一个 C、C++ 和 Objective-C 编译器前端，基于 LLVM 项目。Apple Clang 是 macOS 和 Xcode 的默认编译器，专门为 Apple 的硬件和软件生态系统进行了优化。

你可以使用 Apple Clang 编译你的 C++ 代码。以下是如何使用 Apple Clang 编译你提供的代码的步骤：

1. 打开终端。
2. 导航到包含 [`page_15.cpp`](./page_15.cpp") 文件的目录。
3. 使用以下命令编译代码：

```sh
clang++ -o page_15 page_15.cpp
```

4. 编译成功后，运行生成的可执行文件：

```sh
./page_15
```

# macOS上的g++和clang++有什么区别
`g++` 和 `clang++` 是两个不同的 C++ 编译器的驱动程序，但在 macOS 上，它们可能指向同一个实际编译器，即 Clang。

以下是一些详细解释：

1. **`g++` 是 GCC（GNU Compiler Collection）的 C++ 编译器**：
   - 在许多系统上，`g++` 指向 GCC 的 C++ 编译器。
   - GCC 是一个开源编译器，支持多种编程语言，包括 C、C++、Fortran 等。

2. **`clang++` 是 Clang 的 C++ 编译器**：
   - Clang 是 LLVM 项目的前端编译器，支持 C、C++、Objective-C 等语言。
   - Clang 以其快速编译时间、详细的错误和警告信息以及模块化设计而闻名。

3. **在 macOS 上的情况**：
   - macOS 默认安装的编译器是基于 Clang 的。
   - 当你在 macOS 上安装 Xcode 或者 Command Line Tools 时，`g++` 和 `clang++` 可能都会指向 Clang 编译器。
   - 这是因为苹果公司维护了一份基于 Clang 的编译工具链，并将其设置为系统的默认编译器。

可以通过以下方式验证 `g++` 和 `clang++` 指向的实际编译器：

```bash
which g++
which clang++
ls -l $(which g++)
ls -l $(which clang++)
```

这些命令将显示它们的实际路径和是否是符号链接指向同一个文件。

### 验证示例

1. **查看 `g++` 和 `clang++` 的路径**：
   ```bash
   which g++
   which clang++
   ```

2. **查看它们是否是符号链接并指向同一个文件**：
   ```bash
   ls -l $(which g++)
   ls -l $(which clang++)
   ```

如果输出类似于下面这样：

```bash
lrwxr-xr-x  1 root  wheel  5 Aug  1 12:00 /usr/bin/g++ -> clang
lrwxr-xr-x  1 root  wheel  5 Aug  1 12:00 /usr/bin/clang++ -> clang
```

这表示 `g++` 和 `clang++` 实际上都是指向 `clang`。

因此，在 macOS 上，尽管 `g++` 和 `clang++` 是不同的编译器驱动程序的名称，但它们都可能指向同一个 Clang 编译器。

于是我尝试了一下，发现确实如此：

```bash
➜  leetcode_cpp git:(main) ✗ ls -l $(which g++)
-rwxr-xr-x  77 root  wheel  119008  5  7 15:01 /usr/bin/g++

➜  leetcode_cpp git:(main) ✗ ls -l $(which clang++)
-rwxr-xr-x  77 root  wheel  119008  5  7 15:01 /usr/bin/clang++
```

从你提供的输出来看，`/usr/bin/g++` 和 `/usr/bin/clang++` 是两个不同的文件，但它们具有相同的大小和时间戳，这表明它们实际上是相同的二进制文件，即它们指向同一个编译器。

这进一步证明在 macOS 上，`g++` 和 `clang++` 都指向 Clang 编译器。苹果在 Xcode 和 Command Line Tools 中通过这种方式来确保兼容性和一致性。

总结：
- **`g++`** 和 **`clang++`** 在你的系统上实际上是相同的 Clang 编译器。
- 这是苹果的设计决定，使得用户可以使用熟悉的 `g++` 和 `clang++` 命令，而无需关心底层编译器的具体实现。

所以，在 macOS 上，无论你使用 `g++` 还是 `clang++`，它们都会调用 Clang 编译器来编译你的 C++ 代码。

The code in folder `GCC_4_7_0` and `GCC_pre_C11` and downloaded from [this linkage](https://www.informit.com/store/c-plus-plus-primer-9780321714114).
