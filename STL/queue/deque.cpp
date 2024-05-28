#include<iostream>
#include<deque>
using namespace std;

void printDeque(const deque<int> &d){
    for(deque<int>::const_iterator it = d.begin(); it!= d.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_front(i);
    }
    printDeque(d);
    deque<int> d1;
    d1 = d;
    printDeque(d1);

    deque<int> d2;
    d2.assign(d.begin(), d.end());
    printDeque(d2);

    deque<int> d3;
    d3.assign(10, 100);
    printDeque(d3);
    
    

    
}

void test2(){
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    printDeque(d);
    
    cout<<"siee:"<<d.size()<<endl;
    cout<<"empty:"<<d.empty()<<endl;
    cout<<"front:"<<d.front()<<endl;
    cout<<"back:"<<d.back()<<endl;

    d.resize(18,0);
    printDeque(d);

    d.resize(5);
    printDeque(d);

}

void test3(){
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    printDeque(d);

    d.push_back(100);
    d.push_front(100);
    printDeque(d);

    d.pop_back();
    d.pop_front();
    printDeque(d);

    d.insert(d.begin(), 10);
    printDeque(d);
    d.insert(d.end(), 2,10);
    printDeque(d);
    
    d.erase(d.begin(),d.end());
    printDeque(d);


}

int main(){
    test3();
    return 0;
}