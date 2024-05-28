#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
void Insertsort(T *arr,int len,bool flag){
    for(int i=1;i<len;i++){
        T key=arr[i];
        int j=i-1;
        if(flag){
            while(j>=0&&arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        else{
            while(j>=0 && arr[j]<key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
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
    Insertsort(arr.data(),len,true);
    cout<<"����� ����"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"����� ����"<<endl;
    Insertsort(arr.data(),len,false);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}