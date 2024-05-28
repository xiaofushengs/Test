#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <string>

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
        table[index].emplace_back(key, value);
        ++numElements;
    }

    void remove(const K& key, const V& value) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key && it->value == value) {
                table[index].erase(it);
                --numElements;
                return;
            }
        }
        throw invalid_argument("Key-Value pair not found");
    }

    list<V> search(const K& key) const {
        int index = hashFunction(key);
        list<V> values;
        for (const auto& kvp : table[index]) {
            if (kvp.key == key) {
                values.push_back(kvp.value);
            }
        }
        if (values.empty()) {
            throw invalid_argument("Key not found");
        }
        return values;
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
    hashTable.insert(1, "uno");
    hashTable.insert(2, "two");
    hashTable.insert(3, "three");
    hashTable.insert(3, "tres");

    cout << "HashTable contents:" << endl;
    hashTable.printHashTable();

    // list<string> values = hashTable.search(1);
    // cout << "Values for key 1: ";
    // for (const auto& value : values) {
    //     cout << value << " ";
    // }
    // cout << endl;

    // hashTable.remove(3, "tres");
    // cout << "HashTable contents after removing key 3 with value 'tres':" << endl;
    // hashTable.printHashTable();

    return 0;
}
