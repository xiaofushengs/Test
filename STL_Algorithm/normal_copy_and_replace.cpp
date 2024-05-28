#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


// copy // 容器内指定范围的元素拷贝到另一容器中
void print(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    vector<int> v2;
    v2.resize(v.size());
    copy(v.begin(),v.end(),v2.begin());
    for_each(v2.begin(),v2.end(),print);
    cout<<endl;
}

// replace // 将容器内指定范围的旧元素修改为新元素
void test02(){
    vector<int> v;
    for(int i=0; i<10; i++){
        int random=rand()%100;
        v.push_back(random);
        v.push_back(5);
    }
    for_each(v.begin(),v.end(),print);
    cout<<endl;
    replace(v.begin(),v.end(),5,100);
    for_each(v.begin(),v.end(),print);
    cout<<endl;
}

// replace_if  // 容器内指定范围满足条件的元素替换为新元素
class replace_if_my{
    public:
        bool operator()(int val){
            return val>=30;
        }
};
void test03(){
    vector<int> v;
    for(int i=0; i<10; i++){
        int random=rand()%100;
        v.push_back(random);
        v.push_back(5);
    }
    for_each(v.begin(),v.end(),print);
    cout<<endl;
    replace_if(v.begin(),v.end(),replace_if_my(),100);
    for_each(v.begin(),v.end(),print);
    cout<<endl;
}

// swap // 互换两个容器的元素

void test04(){
    vector<int> v1;
    for(int i=0; i<10; i++){
        v1.push_back(i);
    }
    vector<int> v2;
    for(int i=10; i<20; i++){
        v2.push_back(i);
    }
    for_each(v1.begin(),v1.end(),print);
    cout<<endl;
    for_each(v2.begin(),v2.end(),print);
    cout<<endl;
    swap(v1,v2);
    for_each(v1.begin(),v1.end(),print);
    cout<<endl;
    for_each(v2.begin(),v2.end(),print);
    cout<<endl;
}
int main() {
    test04();
    return 0;
}


// copy // 容器内指定范围的元素拷贝到另一容器中
// replace // 将容器内指定范围的旧元素修改为新元素
// replace_if  // 容器内指定范围满足条件的元素替换为新元素
// swap // 互换两个容器的元素