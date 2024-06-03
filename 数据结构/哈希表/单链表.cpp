#include<iostream>
#include<list>
#include<vector>
#include<stdexcept>
#include<map>

using namespace std;

template<typename K,typename V>
class HashTable_single{
    private:
        struct Node{
            K key;
            V value;
            Node(K ke,V val):key(ke),value(val){}
        };
        
        vector<list<Node>> table;
        int numElements;
        int capacity;

        int hashFunction(const K& key) const {
            return static_cast<int>(key) % capacity;
        }

    public:

        HashTable_single(){
            this->capacity=10;
            this->numElements=0;
            table.resize(this->capacity);
        }

        void insert(const K& key,const V& value){
            int index=hashFunction(key);
            for(auto& kv:table[index]){
                if(kv.key==key){
                    kv.value=value;
                    return;
                }
            }
            table[index].emplace_back(key,value);
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

        void remove(const K& key){
            int index=hashFunction(key);
            for(auto it=table[index].begin();it!=table[index].end();it++){
                if(it->key==key){
                    table[index].erase(it);
                    --numElements;
                    return;
                }
            }
            throw invalid_argument("Key not found");
        }

        V search(const K& key)const{
            int index=hashFunction(key);
            for(const auto& kv:table[index]){
                if(kv.key==key){
                    return kv.value;
                }
            }
            throw invalid_argument("Key not found");
        }

        bool isEmpty()const{
            if(numElements==0){
                return true;
            }
            return false;
        }

        int getsize()const{
            return numElements;
        }

};


int main(){
    HashTable_single<int, string> hashTable;

    hashTable.insert(1, "one");
    hashTable.insert(1, "one1");
    hashTable.insert(2, "two");
    hashTable.insert(3, "three");
    hashTable.insert(4, "four");
    hashTable.insert(5, "five");
    hashTable.printHashTable();
    cout<<"É¾³ýÔªËØ"<<endl;
    hashTable.remove(5);
    hashTable.printHashTable();
    cout<<hashTable.search(3)<<endl;
    cout<<hashTable.getsize()<<endl;
    cout<<hashTable.isEmpty()<<endl;

    return 0;

}