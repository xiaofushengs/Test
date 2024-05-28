#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;
};

class mycompare {
public:
    bool operator()(const Person& p1, const Person& p2) const
    {
        return p1.age > p2.age;
    }
};

void test() {
    map<Person, int, mycompare> m;  // 将 map 的键类型改为 Person
    string name_seed = "ABCDEFG";
    for (int i = 0; i < name_seed.size(); i++) {
        string name = "Person_";
        name += name_seed[i];
        Person p;
        p.name = name;
        int age = rand() % 13 + 18;
        p.age = age;
        m.insert(make_pair(p, i + 101));  // 插入时键为 Person，值为 int
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first.name << " " << i->first.age << " " << i->second << endl;
    }
}

int main() {
    test();
    return 0;
}
