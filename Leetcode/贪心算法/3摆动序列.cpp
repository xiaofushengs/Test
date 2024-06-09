#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

pair<int,vector<int>> wiggleMaxLength(vector<int>& v){
    vector<int> v1;
    v1.push_back(v[0]);
    int prediff=0;
    int curdiff=0;
    int count=1;
    for (int i = 0; i < v.size()-1; i++)
    {
        curdiff=v[i+1]-v[i];
        if((prediff>=0 && curdiff<0)||(prediff<=0 && curdiff>0)){
            count++;
            prediff=curdiff;
            v1.push_back(v[i+1]);
        }
    }
    return make_pair(count,v1);
}

int main(){
    int len=0;
    cout<<"请输入数据长度"<<endl;
    cin>>len;
    vector<int> v(len);
    for (int i = 0; i < len; i++)
    {
        cin>>v[i];
    }
    pair<int,vector<int>> result=wiggleMaxLength(v);
    cout<<"数组长度:"<<result.first<<endl;
    cout<<"具体数值:";
    for(auto val:result.second){
        cout<<val<<" ";
    }
    cout<<endl;
    
    return 0;
}