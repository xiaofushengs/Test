#include <iostream>
using namespace std;

template<typename T>
void Select_Sort(T *arr,int len,bool flag) {
    int i,j,max_min;
    for(i=0;i<len;i++){
        max_min=i;
        for(j=i+1;j<len;j++){
            if(flag){
                if(arr[max_min]>arr[j])
                    max_min=j;
            }
            else{
                if(arr[max_min]<arr[j])
                    max_min=j;
            }
        }
        if(max_min!=i){
            swap(arr[i],arr[max_min]);
        }
    }
    
}

int main(){
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    Select_Sort(arr,10,true);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}