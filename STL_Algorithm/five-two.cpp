#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class TransForm{
    public:
        int operator()(int val){
            return val;
        }
};

class myprint{
    public:
        void operator()(int val){
            cout<<val<<" ";
        }
};

void test(){

    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int> vt;
    transform(v.begin(),v.end(),vt.begin(),TransForm());
    for_each(vt.begin(),vt.end(),myprint());
}

int main(){
    test();
    return 0;
}