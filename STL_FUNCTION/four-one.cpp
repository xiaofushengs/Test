#include<iostream>
#include<string>
using namespace std;

class myadd{
    public:
        int operator()(int a,int b){
            return a+b;
        }
};
void test01(){
    myadd my;
    cout<<my(10,20)<<endl;
}

int main(){
    test01();
    return 0;
}