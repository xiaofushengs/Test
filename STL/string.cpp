#include<iostream>
#include<string>
using namespace std;

//赋值操作
void test01(){
    string s1="helllo world";
    string s2;
    s2=s1;
    cout<<s1<<endl;
    cout<<s2<<endl;
    s2+=" xiao fu sheng";
    cout<<s2<<endl;
    string s3;
    s3.assign(s1);
    cout<<s3<<endl;
    string s4;
    s4.assign("helllo world",5);
    cout<<s4<<endl;

    string s5;
    s5.assign(5,'s');
    cout<<s5<<endl;


}
//查找和替换
void test02(){
    string s1="hello 5 world5";
    int pos=s1.find("5");
    if(pos!=-1){
        cout<<pos<<endl;
    }else
    {
        cout<<"no found"<<endl;
    }
    s1.replace(pos,2,"haha");
    cout<<s1<<endl;
    

}
//字符存取
void test03(){
    string s1="hello world";
    
    cout<<s1<<endl;
    for (int i = 0; i < s1.size(); i++)
    {
        cout<<s1[i]<<" ";
    }
    cout<<endl;
    for (size_t i = 0; i < s1.size(); i++)
    {
        cout<<s1.at(i)<<" ";
    }
    cout<<endl;
    
    
}
void test04(){
    string s1="zhangsan";
    cout<<s1<<endl;

    s1.append("lisi");
    cout<<s1<<endl;

    s1.insert(1,"wangwu");
    cout<<s1<<endl;

    s1[1]='x';
    cout<<s1<<endl;

    s1.erase(0,s1.size());
    cout<<s1<<endl;

}

void test05(){
    string s1="hello world";
    int pos=s1.find(" ");
    string s2=s1.substr(0,pos);
    cout<<s2<<endl;
}
int main(){
    test05();
    return 0;
}