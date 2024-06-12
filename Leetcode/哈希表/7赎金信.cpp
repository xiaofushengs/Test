#include<iostream>
#include<string>

using namespace std;

bool canConstruct(string ransomNote, string magazine){
    int recode[26]={0};
    for (int i = 0; i < magazine.size(); i++)
    {
        recode[magazine[i]-'a']++;
    }
    for (int i = 0; i < ransomNote.size(); i++)
    {
        recode[ransomNote[i]-'a']--;
        if(recode[ransomNote[i]-'a']<0){
            return false;
        }
    }
    return true;
    
    
}


int main(){
    cout<<"请输入赎金信 "<<endl;
    string s1;
    cin>>s1;
    cout<<"请输入杂志"<<endl;
    string s2;
    cin>>s2;
    int result=canConstruct(s1,s2);
    if(result){
        cout<<"ture";
    }else
    {
        cout<<"false";
    }
    
    
    

    return 0;
}