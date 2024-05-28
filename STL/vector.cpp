#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int> &v){
   for(vector<int>::iterator i = v.begin(); i != v.end();i++){
    cout<<*i<<" ";
   }
   cout<<endl;
}
void test1(){
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
       if(i%2 == 0){
         v.push_back(i);
       }
    }
    printVector(v);

    vector<int> v2;
    v2 = v;
    printVector(v2);

    vector<int> v3;
    v3.assign(v.begin(),v.end());
    printVector(v3);

    vector<int> v4;
    v4.assign(10,100);
    printVector(v4);

    cout<<"size:"<<v.size()<<endl;
    cout<<"capacity:"<<v.capacity()<<endl;
    cout<<"max_size:"<<v.max_size()<<endl;
    v.resize(15,0);
    printVector(v);
    v.resize(5);
    printVector(v);
    
}

void test2(){
    vector<int> v;
    for(int i = 1; i <= 5; i++){
        v.push_back(i);
    }
    printVector(v);
    v.pop_back();
    printVector(v);

    v.insert(v.begin(),100);
    printVector(v);
    v.insert(v.end(),1000);
    printVector(v);
    v.insert(v.end(),2,99);
    printVector(v);

    v.erase(v.begin());
    printVector(v);
    v.erase(v.begin(),v.end());
    printVector(v);
}

void test3(){
    vector<int> v;
    for(int i = 1; i <= 5; i++){
        v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    vector<int> v1;
    for (int i = 5; i>0; i--)
    {
        v1.push_back(i);
    }
    printVector(v1);
    v1.swap(v);
    printVector(v);
    printVector(v1);

    
    
}


int main(){
    test3();
    return 0;
}