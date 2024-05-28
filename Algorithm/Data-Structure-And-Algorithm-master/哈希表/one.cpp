#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename K, typename V>
class HashTable {
private:
    struct KeyValuePair {
        K key;
        V value;
        KeyValuePair(K k, V v) : key(k), value(v) {}
    };

    vector<list<KeyValuePair>> table;
    int numElements;
    int capacity;

    int hashFunction(const K& key) const {
        return static_cast<int>(key) % capacity;
    }

public:
    HashTable(int tableSize = 10) : capacity(tableSize), numElements(0) {
        table.resize(capacity);
    }

    void insert(const K& key, const V& value) {
        int index = hashFunction(key);
        for (auto& kvp : table[index]) {
            if (kvp.key == key) {
                kvp.value = value; // 如果键已经存在，则更新值
                return;
            }
        }
        table[index].emplace_back(key, value);
        ++numElements;
    }

    void remove(const K& key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                --numElements;
                return;
            }
        }
        throw invalid_argument("Key not found");
    }

    V search(const K& key) const {
        int index = hashFunction(key);
        for (const auto& kvp : table[index]) {
            if (kvp.key == key) {
                return kvp.value;
            }
        }
        throw invalid_argument("Key not found");
    }

    bool isEmpty() const {
        return numElements == 0;
    }

    int getSize() const {
        return numElements;
    }

    void printHashTable() const {
        for (int i = 0; i < capacity; ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& kvp : table[i]) {
                cout << "{" << kvp.key << ": " << kvp.value << "} ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable<int, string> hashTable;

    hashTable.insert(1, "one");
    hashTable.insert(1, "one1");
    hashTable.insert(2, "two");
    hashTable.insert(3, "three");
    hashTable.insert(4, "four");
      hashTable.insert(5, "five");

    cout << "HashTable contents:" << endl;
    hashTable.printHashTable();

    // cout << "Value for key 2: " << hashTable.search(2) << endl;

    // hashTable.remove(3);
    // cout << "HashTable contents after removing key 3:" << endl;
    // hashTable.printHashTable();

    return 0;
}
