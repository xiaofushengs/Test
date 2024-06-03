#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void sortedSquares_one(vector<int>& v){
    for (int i = 0; i < v.size(); i++)
    {
        v[i]*=v[i];
    }
    sort(v.begin(),v.end());
}


vector<int> sortedSquares(vector<int>& v){
    vector<int> v1(v.size(),0);
    int i=0,j=v.size()-1;
    int k=v.size()-1;
    while(i<=j){
        if(v[i]*v[i]<v[j]*v[j]){
            v1[k--]=v[j]*v[j];
            j--;
        }
        else
        {
            v1[k--]=v[i]*v[i];
            i++;
        }
        
    }
    return v1;

}


void test1(){
    vector<int> v={-4,-1,0,3,10};
    sortedSquares_one(v);
    for_each(v.begin(),v.end(),[](int val){
        cout<<val<<" ";
    });
    cout<<endl;
}

void test2(){
    vector<int> v={-7,-3,2,3,11};
    vector<int> v2=sortedSquares(v);
    for_each(v2.begin(),v2.end(),[](int val){
        cout<<val<<" ";
    });
    cout<<endl;
}




int main(){
    test2();
    return 0;
}