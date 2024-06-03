#include<iostream>
#include<string>

using namespace std;

string swapPair(string& s){
    int low=0;
    int higt=s.size()-1;
    while (low<higt)
    {
        swap(s[low],s[higt]);
        low++;
        higt--;
    }
    return s;
    
}

int main(){
    string s="hello";
    cout<<swapPair(s)<<endl;
}