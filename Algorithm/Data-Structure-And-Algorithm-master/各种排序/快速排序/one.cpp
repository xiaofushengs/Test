#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<"��������Ҫ����Ԫ�صĸ�����"<<endl;
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"������Ҫ�����Ԫ�أ�"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}