#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class GreaterTen{
    public:
        bool operator()(int x){
            return x>5;
        }
};

void test(){
    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    auto pos=find_if(v.begin(), v.end(), GreaterTen());
    if(pos!=v.end()){
        for(;pos !=v.end();pos++){
            cout<<*pos<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}

//find()
void test1(){
    vector<int>  v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    auto pos=find(v.begin(), v.end(), 5);
    if(pos!=v.end()){
        cout<<*pos<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}

//adjacent_find()
void test2(){
    vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
    for_each(v.begin(), v.end(), [](int x){cout<<x<<" ";});
    cout<<endl;
    auto pos=adjacent_find(v.begin(), v.end());
    if(pos!=v.end()){
        cout<<*pos<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}
//binary_search

void test3(){
    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int x){cout<<x<<" ";});
    cout<<endl;
    auto pos=binary_search(v.begin(), v.end(), 1);
    if(pos){
        cout<<pos<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}

//count()
void test4(){
    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(100);
    }
    for_each(v.begin(), v.end(), [](int x){cout<<x<<" ";});
    cout<<endl;
    int coun=count(v.begin(), v.end(), 100);
    if(coun){
        cout<<coun<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

}

//count_if()
void test5(){
    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    int num=count_if(v.begin(), v.end(), [](int x){return x>=5;});
    if(num){
        cout<<num<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
}



int main(){
    test5();
    return 0;
}