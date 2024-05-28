#include<iostream>
#include<set>
using namespace std;

void printset(set<int> &s){
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.insert(60);
    s.insert(40);
    printset(s);

    set<int> s1(s);
    printset(s1);


    

    cout<<"size:"<<s.size()<<endl;
    cout<<"max_size:"<<s.max_size()<<endl;
    cout<<"empty:"<<s.empty()<<endl;

    s.erase(40);
    printset(s);
    s.erase(s.begin());
    printset(s);
    auto it=s.find(20);
    cout<<"find:"<<*it<<endl;

    
}

void printmultiset(multiset<int> &s){
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test02(){
    multiset<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.insert(60);
    s.insert(40);
    printmultiset(s);
    s.erase(10);
    printmultiset(s);
    auto t=s.count(40);
    cout<<"count:"<<t<<endl;
    auto it=s.find(40);
    cout<<"find:"<<*it<<endl;
    s.erase(it,s.end());
    printmultiset(s);


    
}

class Person{
    public:
        Person(string name,int age){
            this->name=name;
            this->age=age;
        }
        string name;
        int age;
};
class compareperson{
    public:
        bool operator()(Person &p1,Person &p2)const
        {
            return p1.age>p2.age;
        }
};

void test03(){
    set<Person,compareperson> s;
    Person p1("Áõ±¸", 23);
	Person p2("¹ØÓğ", 27);
	Person p3("ÕÅ·É", 25);
	Person p4("ÕÔÔÆ", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for(auto it=s.begin();it!=s.end();it++){
		cout<<"ĞÕÃû:"<<it->name<<" ÄêÁä:"<<it->age<<endl;
	}
}


int main(){
    test03();
    return 0;
}