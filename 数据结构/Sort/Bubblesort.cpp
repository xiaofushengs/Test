#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
void Bubblesort(T *arr,int len,bool flag){
    int i,j;
    for(i=0;i<len-1;i++){
        for(j=0;j<len-i-1;j++){
            if(flag){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
            
            else{
                if(arr[j]<arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
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
    Bubblesort(arr.data(),len,true);
    cout<<"����� ����"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"����� ����"<<endl;
    Bubblesort(arr.data(),len,false);
    for_each(arr.begin(),arr.end(),[](int x){cout<<x<<" ";});
    cout<<endl;
    return 0;
}