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
    cout<<"请输入元素个数"<<endl;
    int len;
    cin>>len;
    vector<int> arr(len);
    cout<<"请输入元素"<<endl;
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
    Bubblesort(arr.data(),len,true);
    cout<<"排序后 正序"<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"排序后 逆序"<<endl;
    Bubblesort(arr.data(),len,false);
    for_each(arr.begin(),arr.end(),[](int x){cout<<x<<" ";});
    cout<<endl;
    return 0;
}