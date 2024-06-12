#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int fourNumsadd(vector<int>& v1,vector<int>& v2,vector<int>& v3,vector<int>& v4){
    unordered_map<int,int> map;
    for(int a:v1){
        for(int b:v2){
            map[a+b]++;
        }
    }
    int count=0;
    for(int c:v3){
        for(int d:v4){
            if(map.find(0-(c+d))!=map.end()){
                count+=map[0-(c+d)];
            }
        }
    }
    return count;
}

int main(){

    
    vector<int> v1={1,2};
    vector<int> v2={-2,-1};
    vector<int> v3={-1,2};
    vector<int> v4={0,2};
    cout<<"元组有几个:"<<fourNumsadd(v1,v2,v3,v4)<<endl;

    return 0;
}