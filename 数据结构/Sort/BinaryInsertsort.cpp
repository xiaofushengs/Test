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
    cout<<"������Ԫ�ظ���"<<endl;
    int len;
    cin>>len;
    vector<int> arr(len);
    cout<<"������Ԫ��"<<endl;
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
    cout<<"����ǰ"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    BinaryInsertSort(arr.data(),len,true);
    cout<<"����� ����"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"����� ����"<<endl;
    BinaryInsertSort(arr.data(),len,false);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}