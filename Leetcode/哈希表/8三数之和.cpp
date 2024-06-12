#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<vector<int>> threesum(vector<int>& nums){
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]>0){
            return result;
        }
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int left=i+1;
        int right=nums.size()-1;
        while (left<right)
        {
            if(nums[i]+nums[left]+nums[right]>0) right--;
            else if(nums[i]+nums[left]+nums[right]<0) left++;
            else{
                result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                while(left<right && nums[right]==nums[right-1]) right--;
                while(left<right && nums[left]==nums[left+1]) left++;
                right--;
                left++;
            }
        }
        

        
    }
    return result;
    
    
}


int main(){
    vector<int> nums={-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result=threesum(nums);
    for (const auto& innerVec : result) {
        std::cout << "[";
        for (size_t i = 0; i < innerVec.size(); ++i) {
            std::cout << innerVec[i];
            if (i < innerVec.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }


    return 0;
    
}