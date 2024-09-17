#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& nums){
    int k=nums.size()-1;
    vector<int> result(nums.size(),0);
    for (int i = 0, j = nums.size()-1; i<j;)
    {
        if(nums[i]*nums[i]<nums[j]*nums[j]){
            result[k--]=nums[j]*nums[j];
            j--;
        }else{
            result[k--]=nums[i]*nums[i];
            i++;
        }
    }
    return result;
}

int main(){
    vector<int> v={-4,-1,0,3,10};
    for_each(v.begin(),v.end(),[](int val){
        cout<<val<<",";
    });
    cout<<endl;
    vector<int> v1=sortedSquares(v);
    for_each(v1.begin(),v1.end(),[](int val){
        cout<<val<<",";
    });
    cout<<endl;
    return 0;
}