#include<iostream>
#include<set>
#include<string>

using namespace std;

class Person{
    public:
        Person(string name,int age){
            this->name=name;
            this->age=age;
        }
        string name;
        int age;

};
class comparePerson
{
public:
	bool operator()(const Person& p1, const Person &p2)const
	{
		//按照年龄进行排序  降序
		return p1.age > p2.age;
	}
};

void createSet(set<Person,comparePerson> &s){
    string name_INDEX="ABCDEFG";
    for(int i=0;i<7;i++){
        string name="TOM ";
        name+=name_INDEX[i];
        int age=rand()%21+10;
        Person p(name,age);
        s.insert(p);
    }
}


void test01(){
    set<Person,comparePerson>  s;
    createSet(s);
    for(set<Person>::iterator it=s.begin();it!=s.end();it++){
        cout<<"name:"<<it->name<<" age:"<<it->age<<endl;
    }

}
int main(){
    test01();
    return 0;
}