#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


// find //查找元素
// find_if //按条件查找元素
// adjacent_find //查找相邻重复元素
// binary_search //二分查找法
// count //统计元素个数
// count_if //按条件统计元素个数

void test01(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>::iterator pos = find(v.begin(),v.end(),5);
    if(pos!=v.end()){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}

class Person{
    public:
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    bool  operator==(const Person &p){
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age){
            return true;
        }
        else{
            return false;
        }
    }
    public:
        string m_Name;
        int m_Age;
};
void test02(){
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    vector<Person>::iterator pos = find(v.begin(),v.end(),p3);
    if(pos!=v.end()){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}

// find_if //按条件查找元素
class Greater{
    public:
        bool operator()(int val){
            return val>5;
        }
};
void test03(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>::iterator pos = find_if(v.begin(),v.end(),Greater());
    if(pos!=v.end()){
        
        cout<<*pos<<" ";
    }
    else{
        cout<<"no"<<endl;
    }
}

class Greater2{
    public:
        bool operator()(Person &p){
            return p.m_Age>40;
        }
};
void test04(){
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    vector<Person>::iterator pos = find_if(v.begin(),v.end(),Greater2());
    if(pos!=v.end()){
        cout<<pos->m_Name<<" "<<pos->m_Age<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}
int main()
{
    test04();
    return 0;
}