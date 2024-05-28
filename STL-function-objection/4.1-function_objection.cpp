#include<iostream>
#include<string>

using namespace std;

class Myadd{
    public:
        int operator()(int v1,int v2){
            return v1+v2;
        }
};

void test(){
    Myadd add;
    cout<<add(10,20)<<endl;
    
}
int main()
{
    test();
    return 0;
    
}