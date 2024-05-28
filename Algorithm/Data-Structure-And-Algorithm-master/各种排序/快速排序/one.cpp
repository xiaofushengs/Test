#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<"请输入你要排序元素的个数："<<endl;
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"请输入要排序的元素："<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}