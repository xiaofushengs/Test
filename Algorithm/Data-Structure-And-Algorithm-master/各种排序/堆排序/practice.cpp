#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void Heapjust(T *arr,int start,int end){
    T temp=arr[start];
    int i=start*2+1;  //左子节点
    while(i<=end){
        if(i+1<=end && arr[i+1]>arr[i]){
            i++;
        }
        if(arr[i]<=temp){
            break;
        }
        arr[start]=arr[i];
        start=i;
        i=start*2+1;
    }
    arr[start]=temp;
}

template<typename T>
void HeapSort(T *arr,int len){
    for(int i=len/2-1;i>=0;i--){
        Heapjust(arr,i,len-1);
    }
    for(int i=len-1;i>0;i--){
        swap(arr[0],arr[i]);
        Heapjust(arr,0,i-1);
    }
}

int main(){
    int n=0;
    cout<<"请输入数组长度："<<endl;
    cin>>n;
    vector<double> arr(n);
    cout<<"请输入数组元素："<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    HeapSort(arr.data(),n);
    cout<<"排序后的数组："<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}