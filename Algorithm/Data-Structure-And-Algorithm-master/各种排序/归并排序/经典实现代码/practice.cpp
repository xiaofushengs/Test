#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void Merge(vector<T>& v1, vector<T>& v2,int start,int mid,int end){
    int i=start;
    int j=mid+1;
    int k=start;
    while(i<=mid && j<=end){
        if(v1[i]<=v1[j])
            v2[k++]=v1[i++];
        else
            v2[k++]=v1[j++];
    }

    while(i<=mid){
        v2[k++]=v1[i++];
    }
    while(j<=end){
        v2[k++]=v1[j++];
    }
    for(i=0;i<k;i++){
        v1[i]=v2[i];
    }
    
}

template<typename T>
void Msort(vector<T> &v,vector<T>& v2,int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        Msort(v,v2,start,mid);
        Msort(v,v2,mid+1,end);
        Merge(v,v2,start,mid,end);
    }
}

template<typename T>
void MergeSort(vector<T> &v){
    vector<T> v2(v.size());
    Msort(v,v2,0,v.size()-1);
}

int main(){
    vector<double> v;
    for (int i = 0; i < 10; i++)
    {
        double random=(rand()%101)/10.f;
        v.push_back(random);
    }
    cout<<"ÅÅÐòÇ°"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    MergeSort(v);
    cout<<"ÅÅÐòºó"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
    
}