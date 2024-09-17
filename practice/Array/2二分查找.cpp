#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums,int target){
    int low=0;
    int higt=nums.size()-1;
    while (low<=higt)
    {
        int mid=(low+higt)/2;
        if(nums[mid]<target){
            low=mid+1;
        }else if(nums[mid]>target){
            higt=mid-1;
        }else
        {
            return mid;
        }
         
    }
    return -1;
    
}

int main(){
    vector<int> v={1,2,3,4,7,9,10};
    int result=0;
    cout<<"请输入目标函数"<<endl;
    cin>>result;
    cout<<"输入结果下标：";
    cout<<search(v,result)<<endl;
    return 0;
}