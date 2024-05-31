#include<iostream>
#include<vector>
using namespace std;

int BinarySort(vector<int> &v,int target){
   int low=0;
   int high=v.size()-1;
   while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]<target){
            low=mid+1;
        }
        else if(v[mid]>target){
            high=mid-1;
        }
        else{
            return mid;
        }

   }
   return -1;
}

int main(){
    vector<int> v={-1,0,3,5,9,12};
    cout<<"请输入目标数字:"<<endl;
    int target=0;
    cin>>target;
    int result=BinarySort(v,target);
    cout<<result<<endl;
    return 0;
}