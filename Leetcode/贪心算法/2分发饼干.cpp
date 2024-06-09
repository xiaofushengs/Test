#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findContentChildren(vector<int>& g,vector<int>& s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());

    int index=s.size()-1;
    int result=0;
    for (int i = g.size()-1; i >= 0; i--)
    {
        if(index>=0 && s[index]>=g[i]){
            result++;
            index--;
        }
    }
    return result;
}


int main(){
    vector<int> g={1,2,3};
    vector<int> s={1,3,2};
    int result=findContentChildren(g,s);
    cout<<result<<endl;

    return 0;
}