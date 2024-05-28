#include<iostream>
#include<string>
#include<queue>

using namespace std;

// Queue是一种先进先出(First In First Out,FIFO)的数据结构，它有两个出口


// 入队 --- push
// 出队 --- pop
// 返回队头元素 --- front
// 返回队尾元素 --- back
// 判断队是否为空 --- empty
// 返回队列大小 --- size

class Person{
    public:
        Person(string name,int age){
            this->name = name;
            this->age = age;
        }
        string name;
        int age;
};
void test01(){
    queue<Person> s;
    Person p1("tom1",18);
    Person p2("tom2",19);
    Person p3("tom3",20);
    Person p4("tom4",21);
    Person p5("tom5",22);
    s.push(p1);
    s.push(p2);
    s.push(p3);
    s.push(p4);
    s.push(p5);
    while (!s.empty())
    {
        cout<<"front  name:"<<s.front().name<<"  age:"<<s.front().age<<" ";
        cout<<"back  name:"<<s.back().name<<"  age:"<<s.back().age<<endl;
        s.pop();
    }
    cout<<s.size()<<endl;
    
}
int main(){
    test01();
    return 0;
}