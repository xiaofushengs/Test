#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class print01{
    public:
        void operator()(int i){
            cout<<i<<" ";
        }
};
void print02(int i){
    cout<<i<<" ";
}

void test(){
    vector<int>  v;
    for(int i=10;i>0;i--){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print01());
    cout<<endl;
    for_each(v.begin(),v.end(),print02);
    cout<<endl;
}

int add(int i){
    return i+2;
}

void test2(){
    vector<int>  v;
    for(int i=10;i>0;i--){
        v.push_back(i);
    }
    
    vector<int>  vTarget;
    transform(v.begin(),v.end(),back_inserter(vTarget),add);
    for_each(vTarget.begin(),vTarget.end(),print02);
    cout<<endl;
}

int main(){
    test2();
    return 0;
}