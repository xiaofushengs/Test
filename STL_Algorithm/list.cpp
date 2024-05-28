#include<iostream>
#include<list>
#include<random>

using namespace std;

void printList(const list<int> &list){
    for(auto it=list.begin(); it!=list.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test(){
    list<int> l1;
    
    for(int i=0; i<10; i++){
        l1.push_back(i);
    }
    printList(l1);

    list<int> l2;
    l2=l1;
    printList(l2);

    list<int> l3;
    l3.assign(10,1000);
    printList(l3);

    list<int> l4;
    l4.assign(l1.begin(), l1.end());
    printList(l4);
}


void test1(){
    list<int> l1;
    for(int i=0; i<10; i++){
        l1.push_back(i);
    }
    printList(l1);

    list<int> l2;
    for(int i=10;i>0;i--){
        l2.push_back(i);
    }
    printList(l2);
    cout<<"----------------"<<endl;
    l1.swap(l2);
    printList(l1);
    printList(l2);
    cout<<"size:"<<l1.size()<<" "<<l2.size()<<endl;
    cout<<"front:"<<l1.front()<<" "<<l2.front()<<endl;
    cout<<"back:"<<l1.back()<<" "<<l2.back()<<endl;
    cout<<"empty:"<<l1.empty()<<" "<<l2.empty()<<endl;
    cout<<"max_size:"<<l1.max_size()<<" "<<l2.max_size()<<endl;
    cout<<"----------------"<<endl;
}

void test2(){
    list<int>  lis;
    lis.push_back(10);
    lis.push_back(20);
    lis.push_back(30);
    lis.push_front(100);
    lis.push_front(200);
    lis.push_front(300);
    printList(lis);

    //Õ∑delete
    lis.pop_front();
    printList(lis);
    //Œ≤delete
    lis.pop_back();
    printList(lis);

    cout<<"--------------------------------"<<endl;
    auto it=lis.begin();
    lis.insert(++it,1000);
    printList(lis);

    auto it2=lis.end();
    it2--;
    lis.erase(it2);
    printList(lis);

    lis.remove(1000);
    printList(lis);

    lis.clear();
    printList(lis);
    

}
bool mycopare(int v1, int v2){
    return v1>v2;
}
void test3(){
    list<int> li;
    li.push_back(10);
    li.push_back(20);
    li.push_back(15);
    li.push_back(30);
    li.push_back(25);
    li.push_front(100);
    printList(li);
    li.reverse();
    printList(li);

    li.sort();
    printList(li);

    li.sort(mycopare);
    printList(li);

    li.reverse();
    printList(li);
}

class Person{
    public:
        Person(string name,int age,int height){
            this->m_name = name;
            this->m_age = age;
            this->m_height = height;
        }
        string m_name;
        int m_age;
        int m_height;
};
void printPerson(const list<Person> &list){
    for(auto it=list.begin(); it!=list.end(); it++){
        cout << it->m_name << " " << it->m_age << " " << it->m_height << endl;
    }
    cout << endl;
}
bool comparePerson( Person &p1,  Person &p2){
    if(p1.m_age==p2.m_age){
        return p1.m_height>p2.m_height;
    }
    else{
        return p1.m_age>p2.m_age;
    }
}
void test4(){
    list<Person> li;
    Person p1("¡ı±∏", 35 , 175);
	Person p2("≤‹≤Ÿ", 45 , 180);
	Person p3("ÀÔ»®", 40 , 170);
	Person p4("’‘‘∆", 25 , 190);
	Person p5("’≈∑…", 35 , 160);
	Person p6("πÿ”", 35 , 200);
	li.push_back(p1);
	li.push_back(p2);
	li.push_back(p3);
	li.push_back(p4);
	li.push_back(p5);
	li.push_back(p6);
    printPerson(li);

    li.sort(comparePerson);
    printPerson(li);
    
}

int main(){
    test4();
    return 0;
}