#include<iostream>
#include<string>

using namespace std;

class Person{
    public:
        Person(){
            cout<<"无参构造函数"<<endl;
        }
        Person(int age,int height){
            cout<<"有参构造函数"<<endl;
            m_age = age;
            m_height = new int(height);
        }
        Person(const Person&p){
            cout<<"拷贝构造函数"<<endl;
            m_age = p.m_age;
            m_height = new int(*p.m_height);
        }
        ~Person(){
            cout<<"析构函数"<<endl;
            if(m_height!=NULL){
                delete m_height;
                m_height = NULL;
            }
        }
        int m_age;
        int *m_height;
};
void test(){
    
    Person p2(18,180);
    Person p3(p2);
}

class Circle{
    public:
        Circle(int age){
            this->age=age;
        }
        Circle&  addcircle(Circle p){
            this->age+=p.age;
            return *this;
        }
        int age;
};

void test2(){
    Circle c1(10);
    Circle c2(20);
    c1.addcircle(c2);
    cout<<c1.age<<endl;
    cout<<c2.age<<endl;
    Circle c3 = c1.addcircle(c2).addcircle(c2);
    cout<<c3.age<<endl;
}


int main(){
    test2();
    return 0;
}