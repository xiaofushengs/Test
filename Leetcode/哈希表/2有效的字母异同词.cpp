#include<iostream>
#include<string>

using namespace std;


bool isAnagram(string s1,string s2){
    if(s1.size()!=s2.size()){
        return false;
    }
    int recode[26]={0};
    for (int i = 0; i < s2.size(); i++)
    {
        recode[s2[i]-'a']++;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        recode[s2[i]-'a']--;
        if(recode[s2[i]-'a']<0){
            return false;
        }
    }

    return true;
}

int main(){
    cout<<"ÇëÊäÈës1 "<<endl;
    string s1;
    cin>>s1;
    cout<<"ÇëÊäÈës2"<<endl;
    string s2;
    cin>>s2;
    int result=isAnagram(s1,s2);
    if(result){
        cout<<"ture";
    }else
    {
        cout<<"false";
    }
    return 0;
}