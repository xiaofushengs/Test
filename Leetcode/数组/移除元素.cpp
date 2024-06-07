#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int removeElement(vector<int> &v,int target){
    int slowIndex=0;
    
    for(int fastIndex=0;fastIndex<v.size();fastIndex++){
        if(target!=v[fastIndex]){
            v[slowIndex++]=v[fastIndex];
        }
    }
    v.resize(slowIndex);
    return slowIndex;
}

int main(){
    vector<int> v={0,1,2,3,3,0,4,2,2};
    cout<<"要删除数字:"<<endl;
    int target=0;
    cin>>target;
    int i=removeElement(v,target);
    for_each(v.begin(),v.end(),[](int val){
        cout<<val<<" ";
    });
    cout<<endl;
    cout<<"数字大小:"<<i<<endl;
    
    
}