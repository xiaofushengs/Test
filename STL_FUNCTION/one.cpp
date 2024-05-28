#include<iostream>
#include<stack>
using namespace std;

void test(){
    stack<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }
    while (!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    
}

int main(){
    test();
    return 0;
}