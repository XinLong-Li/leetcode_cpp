`std::unordered_map` 和 `std::map` 都是 C++ 标准库中的关联容器，用于存储键值对，但它们有一些重要的区别：

### `std::unordered_map`:
1. **实现**：
   - 基于哈希表实现。
   
2. **元素顺序**：
   - 元素没有特定的顺序，存储顺序可能与插入顺序不同。

3. **时间复杂度**：
   - 查找、插入和删除操作的平均时间复杂度为 O(1)。
   - 最坏情况下（例如哈希冲突严重时），时间复杂度为 O(n)。

4. **使用场景**：
   - 适用于不需要按顺序访问元素，并且需要高效查找、插入和删除操作的场景。

### `std::map`:
1. **实现**：
   - 基于红黑树（平衡二叉搜索树）实现。

2. **元素顺序**：
   - 元素按键的顺序存储，支持有序遍历。

3. **时间复杂度**：
   - 查找、插入和删除操作的时间复杂度为 O(log n)。

4. **使用场景**：
   - 适用于需要按顺序访问元素，或者需要有序遍历键值对的场景。

### 示例代码：
以下是使用 `std::unordered_map` 和 `std::map` 的示例代码：

```cpp
#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

int main() {
    // 使用 std::unordered_map
    std::unordered_map<std::string, int> unordered_dic;
    unordered_dic["小力"] = 10001;
    unordered_dic["小特"] = 10002;
    unordered_dic["小扣"] = 10003;

    std::cout << "unordered_map:" << std::endl;
    for (const auto& pair : unordered_dic) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 使用 std::map
    std::map<std::string, int> ordered_dic;
    ordered_dic["小力"] = 10001;
    ordered_dic["小特"] = 10002;
    ordered_dic["小扣"] = 10003;

    std::cout << "map:" << std::endl;
    for (const auto& pair : ordered_dic) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

### 输出示例：
由于 `std::unordered_map` 不保证元素顺序，输出顺序可能与插入顺序不同。而 `std::map` 保证按键的顺序存储元素。

```sh
unordered_map:
小力: 10001
小特: 10002
小扣: 10003

map:
小力: 10001
小特: 10002
小扣: 10003
```

### 总结：
- **`std::unordered_map`**：基于哈希表实现，提供无序存储和 O(1) 的平均查找时间，适用于不需要按顺序访问元素的场景。
- **`std::map`**：基于红黑树实现，提供有序存储和 O(log n) 的查找时间，适用于需要按顺序访问元素的场景。
