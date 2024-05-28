#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>

void insert_Sort(T *arr,int len){
    int i,j;
    for(i=1;i<len;i++){
        if(arr[i]<arr[i-1]){
             T temp=arr[i];
            for(j=i-1;j>=0 && arr[j]>temp;j--){
                arr[j+1]=arr[j];
            }
            arr[j+1]=temp;
        }
    }
}

int main(){
    int len=0;
    cout<<"输入数组长度："<<endl;
    cin>>len;
    int arr[len];
    for(int i=0;i<len;i++){
        int rand_num=rand()%100;
        arr[i]=rand_num;
    }
    cout<<"排序前："<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insert_Sort(arr,len);
    cout<<"排序后："<<endl;
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    double arr1[len];
    for(int i=0;i<len;i++){
        double rand_num=(rand()%100)/10.f;
        arr1[i]=rand_num;
    }
    cout<<"排序前："<<endl;
    for(int i=0;i<len;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    insert_Sort(arr1,len);
    cout<<"排序后："<<endl;
    for(int i=0;i<len;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    return 0;
}

