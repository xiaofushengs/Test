#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool IsValid(string &s){
    if(s.size()%2){
        return false;
    }
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='('){
            st.push(')');
        }else if(s[i]=='['){
            st.push(']');
        }else if(s[i]=='{'){
            st.push('}');
        }else if(st.empty() || st.top()!=s[i]){
            return false;
        }else{
            st.pop();
        }
    }
    return st.empty();
}


int main(){
    cout<<"??????¡Á?¡¤???"<<endl;
    string s;
    cin>>s;
    bool result=IsValid(s);
    if(result){
        cout<<"????"<<endl;
    }else{
        cout<<"??????"<<endl;
    }
    return 0;
}