#include<iostream>
using namespace std;


void test(){
    int a=10;
    int &b=a;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<b<<endl;
    cout<<&b<<endl;
    b=20;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<b<<endl;
    cout<<&b<<endl;
    cout<<sizeof(a)<<endl;
}

void test1(){
    int a=10;
    int &b=a;
    int *p=&b;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<*p<<endl;

    *p=20;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<*p<<endl;


}

void test2(){
    int i=42;
    int *p=&i;
    int *&r=p;
    cout<<*p<<endl;
    cout<<*r<<endl;
    cout<<*&r<<endl;
    cout<<i<<endl;
}
int main(){
    test2();
    return 0;
}