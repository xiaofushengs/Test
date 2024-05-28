#include<iostream>
#include<set>
#include<string>

using namespace std;
//打印
void printSet(set<int> &s){
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

}
//赋值
void test1(){
    set<int> s1;
    for (int i = 10; i >0; i--)
    {
        s1.insert(i);
    }
    printSet(s1);
    
    set<int> s2(s1);
    printSet(s2);

    set<int> s3;
    s3=s1;
    printSet(s3);
    
}

//set大小和交换容器
void test2(){
    set<int> s1;
    for (int i = 10; i >0; i--)
    {
        s1.insert(i);
    }
    printSet(s1);
    if(s1.empty()){
        cout<<"s1 is empty"<<endl;
    }else{
        cout<<"s1 is not empty "<<"size:"<<s1.size()<<endl;
    }

    set<int> s2;
    for (int i = 20; i >10; i--)
    {
        s2.insert(i);
    }
    printSet(s2);

    cout<<"sort later"<<endl;
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
    


}
//插入和删除
void test3(){
    set<int> s1;
    for (int i = 10; i >0; i--)
    {
        s1.insert(i);
    }
    printSet(s1);
    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(10);
    printSet(s1);

    s1.clear();
    printSet(s1);
}

//找查和统计
void test4(){
    set<int> s;
    for (int i = 10; i >0; i--){
        s.insert(i);
    }
    printSet(s);

    //查找
    set<int>::iterator it=s.find(5);
    if(it!=s.end()){
        cout<<*it<<endl;
    }else{
        cout<<"not found"<<endl;
    }

    //统计
    int num=s.count(5);
    cout<<num<<endl;
}

//set和multiset的区别
void test5(){
    set<int> s;
    for (int i = 10; i >0; i--){
        s.insert(i);
    }
    printSet(s);

    //multiset
    multiset<int> ms;
    for (int i = 10; i >0; i--){
        ms.insert(i);
    }
    ms.insert(5);
    for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    int num=ms.count(5);
    cout<<num<<endl;
}

//pair队组create
void test6(){
    pair<string,int> p1;
    p1.first="hello";
    p1.second=10;
    cout<<p1.first<<" "<<p1.second<<endl;
}

//set容器排序
class MyCompare{
    public:
        bool operator()(int v1,int v2)const{
            return v1>v2;
        }
        int v1,v2;
};

void test7(){
    set<int> s1;
    for (int i = 10; i >0; i--){
        s1.insert(i);
    }
    printSet(s1);
   //指定排序规则
	set<int,MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main(){
    test7();
    return 0;
}