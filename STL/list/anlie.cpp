#include<iostream>
#include<list>
#include<string>

using namespace std;

class Person{
    public:
        Person(string name,int age,int height){
            this->name=name;
            this->age=age;
            this->height=height;
        }
        string name;
        int age;
        int height;
};
void Createperson(list<Person> &p){
    string name_index="ABCDEFG";
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i=0;i<7;i++){
        string name="TOM ";
        name+=name_index[i];
        
        int age=rand()%21+10;
        int height=rand()%21+160;
        Person p1(name,age,height);
        p.push_back(p1);
    }
}
void printperson(const list<Person> &p){
    for(list<Person>::const_iterator it=p.begin();it!=p.end();it++){
        cout<<"name:"<<it->name<<" age:"<<it->age<<" height:"<<it->height<<endl;
    }
}
bool compare(const Person &p1,const Person &p2){
    if(p1.age==p2.age){
        return p1.height>p2.height;
    }
    else
    {
        return p1.age<p2.age;
    }
    
}
int main(){
    list<Person> people;
    Createperson(people);
    printperson(people);
    people.sort(compare);
    cout<<"sorted:"<<endl;
    printperson(people);
    return 0;
}