#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void test1(){
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={6,7,8,9,10};
    unordered_map<int,int> map;
    for(int A:v1){
        for(int B:v2){
            map[A+B]++;
        }
    }
    for (auto it:map)
    {
         cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }

    
}

void test2(){
    vector<int> v1={1,2,3,4,5,6,7,8,9,10};
    int cutting_point=0;
    for (int i = 0; i < v1.size(); i++)
    {
        if(v1[i]==6){
            cutting_point=i;
            break;
        }
    }
    vector<int> v2(v1.begin(),v1.begin()+cutting_point);
    for(auto it:v2){
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> v3(v1.begin()+cutting_point+1,v1.end());
    for(auto it:v3){
        cout<<it<<" ";
    }
    cout<<endl;

    
}

int main(){
    test2();
    return 0;
}