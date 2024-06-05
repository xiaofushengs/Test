#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
    public:
        string clearBlanck(string& s){
            int low=0;
            for (int quick = 0; quick < s.size(); quick++)
            {
                if(s[quick]!=' '){
                    if (low!=0)
                    {
                         s[low++]=' ';
                    }
                    while (quick<s.size() && s[quick]!=' ')
                    {
                        s[low++]=s[quick++];
                    } 
                }
            }
            s.resize(low);
            return s;
        }

        void reverseArr(string &s,int start,int end){
            int low=start;
            int high=end;
            while (low<high)
            {
                swap(s[low],s[high]);
                low++;
                high--;
            }
        }
};

int main(){
    Solution solution;
    string s=" hello world ";
    cout<<s<<endl;
    cout<<"数组长度："<<s.size()<<endl;

    string s1=solution.clearBlanck(s);
    cout<<s1<<endl;
    cout<<"数组长度："<<s1.size()<<endl;
    solution.reverseArr(s1,0,s1.size()-1);
    cout<<"字符串逆置"<<endl;
    cout<<s1<<endl;
    cout<<"数组长度："<<s1.size()<<endl;

    int start=0;
    for(int i=0;i<=s1.size();i++){
        if(i==s1.size() || s[i]==' '){
            solution.reverseArr(s1,start,i-1);
            start=i+1;
        }
    }
    cout<<s1<<endl;
    
    
}