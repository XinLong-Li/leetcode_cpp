In data structures, the word "hash" refers to the process of converting data (often a key) into a fixed-size integer value, typically using a hash function. This integer value is called a hash code or hash value. The primary purpose of hashing is to enable fast data retrieval.

### Key Concepts:
1. **Hash Function**:
   - A function that takes an input (or key) and returns a fixed-size string of bytes. The output is typically a hash code.
   - Example: `hash(key) -> hash_code`

2. **Hash Code**:
   - The result of the hash function, used to index into an array (hash table) where the actual data is stored.
   - Example: `hash("apple") -> 42`

3. **Hash Table**:
   - A data structure that uses a hash function to map keys to their associated values.
   - Provides average-case constant time complexity (O(1)) for insertions, deletions, and lookups.

4. **Collision**:
   - Occurs when two different keys produce the same hash code.
   - Collision resolution techniques include chaining (linked lists) and open addressing (probing).

### Example:
```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> hashTable;
    hashTable["apple"] = 1;
    hashTable["banana"] = 2;

    std::cout << "apple: " << hashTable["apple"] << std::endl;
    std::cout << "banana: " << hashTable["banana"] << std::endl;

    return 0;
}
```

In this example, `std::unordered_map` is a hash table in C++ that uses hashing to store and retrieve values associated with keys efficiently.