#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <map>

using namespace std;

template<typename K, typename V>
class HashTable_single {
private:
    struct Node {
        K key;
        V value;
        Node(K ke, V val) : key(ke), value(val) {}
    };

    vector<list<Node>> table;
    int numElements;
    int capacity;

    int hashFunction(const K& key) const {
        return static_cast<int>(key) % capacity;
    }

public:
    HashTable_single() {
        this->capacity = 10;
        this->numElements = 0;
        table.resize(this->capacity);
    }

    void insert(const K& key, const V& value) {
        int index = hashFunction(key);
        table[index].emplace_back(key, value);
        numElements++;
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

    void remove(const K& key) {
        int index = hashFunction(key);
        bool found = false;
        for (auto it = table[index].begin(); it != table[index].end();) {
            if (it->key == key) {
                it = table[index].erase(it);
                --numElements;
                found = true;
            } else {
                ++it;
            }
        }
        if (!found) {
            throw invalid_argument("Key not found");
        }
    }

    void search(const K& key) const {
        vector<V> arr;
        int index = hashFunction(key);

        for (const auto& kv : table[index]) {
            if (kv.key == key) {
                arr.push_back(kv.value);
            }
        }

        if (arr.empty()) {
            throw invalid_argument("Key not found");
        }

        for (const auto& val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }

    bool isEmpty() const {
        return numElements == 0;
    }

    int getSize() const {
        return numElements;
    }
};

int main() {
    HashTable_single<int, string> hashTable;

    hashTable.insert(1, "one");
    hashTable.insert(1, "one1");
    hashTable.insert(2, "two");
    hashTable.insert(3, "three");
    hashTable.insert(4, "four");
    hashTable.insert(5, "five");
    hashTable.insert(5, "five1");

    hashTable.printHashTable();
    cout << "Size: " << hashTable.getSize() << endl;
    cout << "Is Empty: " << hashTable.isEmpty() << endl;
    
    cout << "删除所有键为 5 的元素" << endl;
    hashTable.remove(5);
    hashTable.printHashTable();
    
    hashTable.search(1);
    cout << "Size: " << hashTable.getSize() << endl;
    cout << "Is Empty: " << hashTable.isEmpty() << endl;

    return 0;
}
