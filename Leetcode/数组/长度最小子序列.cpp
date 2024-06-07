#include<iostream>
#include<vector>

using namespace std;

int minSubArrayLen(int s,vector<int> & arr){
    int result=__INT32_MAX__;
    int sum=0;
    int i=0; 
    int Sublength=0;
    for (int j = 0; j < arr.size(); j++)
    {
        sum+=arr[j];
        while(sum>=s){
            Sublength=j-i+1;
            result=result<Sublength ? result :Sublength;
            sum-=arr[i++];
        }
    }

    return result==__INT32_MAX__ ? 0:result;
    
}

int main(){
    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
    }
    int m=minSubArrayLen(100,v);
    cout<<m<<endl;
    
}