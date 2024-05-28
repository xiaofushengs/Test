#include<iostream>
#include<map>
#include<string>
using namespace std;

class Person{
    public:
       
        string name;
        int age;
};
void printmap(const map<int,Person> &m){
    
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second.name<<" "<<it->second.age<<endl;
    }
    cout<<endl;
}

void test(){
    map<int,Person> m;
    string name_seed="ABCDEFG";
    for(int i=0;i<name_seed.size();i++){
        string name ="Person_";
        name+=name_seed[i];
        Person p;
        p.name=name;
        int age=rand()%13+18;
        p.age=age;
        m.insert(make_pair(i+101,p));
        
    }
    map<int,Person> m1;
    for(int i=0;i<name_seed.size();i++){
        string name ="Student_";
        name+=name_seed[i];
        Person p;
        p.name=name;
        int age=rand()%21+30;
        p.age=age;
        m1.insert(make_pair(i+101,p));
    }
    printmap(m);
    cout<<"------------"<<endl;
    printmap(m1);
    cout<<"交换后"<<endl;
    m.swap(m1);
    printmap(m);
    cout<<"------------"<<endl;
    printmap(m1);

    
}

void test1(){
    map<int,Person> m;
    string name_seed="ABCDEFG";
    for(int i=0;i<name_seed.size();i++){
        string name ="Person_";
        name+=name_seed[i];
        Person p;
        p.name=name;
        int age=rand()%13+18;
        p.age=age;
        m.insert(make_pair(i+101,p));
        
    }
    printmap(m);
    cout<<"------------"<<endl;
    Person p;
    p.name="小白";
    p.age=20;
    m[10]=p;
    printmap(m);
    cout<<"------------"<<endl;
    m.erase(10);
    printmap(m);
    cout<<"------------"<<endl;
    auto it=m.find(105);
    if(it!=m.end()){
        cout<<(*it).first<<" "<<(*it).second.name<<" "<<(*it).second.age<<endl;
    }
    else{
        cout<<"没有找到"<<endl;
    }
    cout<<"------------"<<endl;
    
    
}

class mycompare{
    public:
        bool operator()( Person &p1, Person &p2)const
        {
            return p1.age>p2.age;
        }
};
void test2(){
    map<int,Person,mycompare> m;
    string name_seed="ABCDEFG";
    for(int i=0;i<name_seed.size();i++){
        string name ="Person_";
        name+=name_seed[i];
        Person p;
        p.name=name;
        int age=rand()%13+18;
        p.age=age;
        m.insert(make_pair(i+101,p));
    }
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->first<<" "<<i->second.name<<" "<<i->second.age<<endl;
    }
}

int main(){
    test2();
    return 0;
}