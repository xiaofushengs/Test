#include<iostream>
#include<string>

using namespace std;

string Reverse(string& s,int k){
   int low=0;
   int high=k-1;
   while (low<high)
   {
        swap(s[low],s[high]);
        low++;
        high--;
   }
   return s;
}

int main(){
    string s="abcdefg";
    int k=0;
    cout<<"������Ҫ��ת��ǰn���ַ�"<<endl;
    cin>>k;
    cout<<Reverse(s,k)<<endl;
}