#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
void BinaryInsertSort(T *arr,int len,bool flag){
    for(int i=1;i<len;i++){
        T temp=arr[i];
        int low=0,high=i-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(flag){
                if(arr[mid]>temp){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(arr[mid]<temp){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            
        }
        for(int j=i-1;j>=low;j--){
            arr[j+1]=arr[j];
        }
        arr[low]=temp;
    }
}

int main(){
    cout<<"请输入元素个数"<<endl;
    int len;
    cin>>len;
    vector<int> arr(len);
    cout<<"请输入元素"<<endl;
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
    cout<<"排序前"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    BinaryInsertSort(arr.data(),len,true);
    cout<<"排序后 正序"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"排序后 倒序"<<endl;
    BinaryInsertSort(arr.data(),len,false);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}