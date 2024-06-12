#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twosum(vector<int>& nums,int target){
    unordered_map<int,int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it=map.find(target-nums[i]);
        if(it!=map.end()){
            return {it->second,i};
        }
        map.insert(pair<int,int>(nums[i],i));
    }
    return {};
}

int main(){
    cout<<"请输入赎金信 "<<endl;
    string s1;
    cin>>s1;
    cout<<"请输入杂志"<<endl;
    string s2;
    cin>>s2;
    int result=canConstruct(s1,s2);
    if(result){
        cout<<"ture";
    }else
    {
        cout<<"false";
    }

    return 0;
}