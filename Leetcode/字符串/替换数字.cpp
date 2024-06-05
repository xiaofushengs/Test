#include<iostream>
#include<string>

using namespace std;

string Replace(string& s){
    int i=s.size()-1;
    int count=0;
    for(int k=0;k<s.size();k++){
        if(s[k]>='0' && s[k]<='9'){
            count++;
        }
    }
    s.resize(s.size()+count*5);
    int j=s.size()-1;
    while(i>=0){
        if(s[i]>='0' && s[i]<='9'){
            s[j--] = 'r';
            s[j--] = 'e';
            s[j--] = 'b';
            s[j--] = 'm';
            s[j--] = 'u';
            s[j--] = 'n';
        }
        else{
            s[j--]=s[i];
        }
        i--;
    }
    return s;
}

int main(){
    string s;
    cout<<"ÇëÊäÈë×Ö·û´®"<<endl;
    cin>>s;
    cout<<Replace(s)<<endl;
}