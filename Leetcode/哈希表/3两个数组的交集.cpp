#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>

using namespace std;

vector<int> intersection(vector<int>& num1,vector<int>& num2){
    unordered_set<int> result;
    unordered_set<int> nums(num1.begin(),num1.end());
    for(auto num:num2){
        if(nums.find(num)!=nums.end()){
            result.insert(num);
        }
    }
    return vector<int>(result.begin(),result.end());
}

int main(){
    vector<int> v1={4,9,5};
    vector<int> v2={9,4,9,8,4};
    vector<int>  v=intersection(v1,v2);
    for(auto num:v){
        cout<<num<<" ";
    }
    cout<<endl;
    
    return 0;
}

