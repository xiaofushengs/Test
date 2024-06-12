#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int getSum(int n){
    int sum=0;
    while (n)
    {
        sum+=(n%10)*(n%10);
        n/=10;
    }
    return sum;
}

bool isHappy(int n){
    unordered_set<int> set;
    while (1)
    {
        int sum=getSum(n);
        if(sum==1){
            return true;
        }

        if(set.find(sum)!=set.end()){
            return false;
        }else{
            set.insert(sum);
        }
        n=sum;
    }
    
}


int main(){
    cout<<"����������"<<endl;
    int n=0;
    cin>>n;
    bool result=isHappy(n);
    if(result){
        cout<<"�ǿ�����"<<endl;
    }else
    {
        cout<<"���ǿ�����"<<endl;
    }
    
    return 0;
}