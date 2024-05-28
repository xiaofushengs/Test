#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;


void test(){
    vector<int>  v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    int total=accumulate(v.begin(),v.end(),0);
    cout<<"total:"<<total<<endl;
    cout<<"size"<<v.size()<<endl;
}


//fill
class myprint{
    public:
        void operator()(int i){
            cout<<i<<" ";
        }
};

void test2(){
    vector<int> v;
    v.resize(10);
    fill(v.begin(),v.end(),100);
    for_each(v.begin(),v.end(),myprint());
    cout<<endl;
}
int main(){
    test2();
    return 0;
}