#include<iostream>
#include<string>
#include<stack>
using namespace std;

// stack是一种先进后出(First In Last Out,FILO)的数据结构，它只有一个出口


void test01(){
    stack<int> s;
    for(int i=1;i<10;i++){
        s.push(i*10);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        cout<<"size num:"<<s.size()<<endl;
        s.pop();
    }
    cout<<endl;
    cout<<"size num:"<<s.size()<<endl;
}

int main(){
    test01();
    return 0;
}

