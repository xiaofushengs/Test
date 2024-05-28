#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void SelectSort(T *arr,int len,bool flag){
    int i,j;
    for(i=0;i<len-1;i++){
        int max_min=i;
        for(j=i+1;j<len;j++){
            if(flag){
                if(arr[j]<arr[max_min]){
                    max_min=j;
                }
            }
            else{
                if(arr[j]>arr[max_min]){
                    max_min=j;
                }
            }
        }
        if(max_min!=i){
            swap(arr[i],arr[max_min]);
        }
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
    SelectSort(arr.data(),len,true);
    cout<<"排序后 正序"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"排序后 倒序"<<endl;
    SelectSort(arr.data(),len,false);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}