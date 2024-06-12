#include<iostream>
#include<vector>
#include<string>

using namespace std;

int Binary(vector<int>& nums,int target){
    int low=0;
    int high=nums.size()-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]<target){
            low=mid+1;
        }else if(nums[mid]>target){
            high=mid-1;
        }else
        {
            return mid;
        }
        
    }
    return -1;
    
}

int main(){
    vector<int> nums={-1,0,3,5,9,12};
    int target=9;
    int result=Binary(nums,target);
    cout<<result<<endl;

    return 0;
}