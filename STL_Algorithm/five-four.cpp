#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// adjacent_find //查找相邻重复元素
// binary_search //二分查找法
// count //统计元素个数
// count_if //按条件统计元素个数


// adjacent_find //查找相邻重复元素
void test(){
    vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
    v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
    vector<int>::iterator it = adjacent_find(v.begin(),v.end());
    if(it!= v.end()){
        cout<<*it<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}

// binary_search //二分查找法
void test1(){
    vector<int> v;
    v.push_back(1);
    for (int i = 0; i < 10; i++)
    {
        /* code */
        v.push_back(i);
    }
    bool ret = binary_search(v.begin(),v.end(),5);
    if(ret){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    
}

// count //统计元素个数

void test2(){
    vector<int> v;
    v.push_back(1);
    for (int i = 0; i < 10; i++)
    {
        /* code */
        v.push_back(7);
    }
    int ret = count(v.begin(),v.end(),7);
    cout<<ret<<endl;
    
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
void test3(){
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("aaa",10);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    Person p("aaa",10);
    int ret = count(v.begin(),v.end(),p);
    cout<<ret<<endl;
}

// count_if //按条件统计元素个数

class Greater{
    public:
        bool operator()(int val){
            return val > 10;
        }
};

void test4(){
    vector<int> v;
    v.push_back(1);
    for (int i = 5; i < 15; i++)
    {
        /* code */
        v.push_back(i);
    }
    int ret = count_if(v.begin(),v.end(),Greater());
    cout<<ret<<endl;
}
class Greater1{
    public:
        bool operator()(Person &p){
            return p.m_Age > 10;
        }
};

void test5(){
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("aaa",10);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    int ret = count_if(v.begin(),v.end(),Greater1());
    cout<<ret<<endl;
}

int main(){
    test5();
    return 0;
}