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
    SelectSort(arr.data(),len,true);
    cout<<"����� ����"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"����� ����"<<endl;
    SelectSort(arr.data(),len,false);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}