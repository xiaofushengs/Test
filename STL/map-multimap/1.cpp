#include<iostream>
#include<map>
#include<string>

using namespace std;
void printMap(map<int,int> &m){
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<"key="<<it->first<<" value="<<it->second<<endl;
    }
    cout<<endl;
}

//赋值
void test1(){
    map<int,int> m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    m1.insert(pair<int,int>(5,50));
    m1.insert(pair<int,int>(6,60));
    m1.insert(pair<int,int>(7,70));
    m1.insert(pair<int,int>(8,80));
    m1.insert(pair<int,int>(9,90));
    m1.insert(pair<int,int>(10,100));
    printMap(m1);

    map<int,int> m2;
    m2=m1;
    printMap(m2);

    map<int,int> m3(m1);
    printMap(m3);

}
//map大小和交换

void test2(){
    map<int,int> m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    m1.insert(pair<int,int>(5,50));
    m1.insert(pair<int,int>(6,60));
    m1.insert(pair<int,int>(7,70));
    m1.insert(pair<int,int>(8,80));
    m1.insert(pair<int,int>(9,90));
    m1.insert(pair<int,int>(10,100));
    printMap(m1);
    cout<<"size="<<m1.size()<<endl;
    cout<<"empty="<<m1.empty()<<endl;
    cout<<endl;

    map<int,int> m2;
    m2.insert(pair<int,int>(11,10));
    m2.insert(pair<int,int>(22,20));
    m2.insert(pair<int,int>(33,30));
    m2.insert(pair<int,int>(44,40));
    m2.insert(pair<int,int>(55,50));
    m2.insert(pair<int,int>(66,60));
    m2.insert(pair<int,int>(77,70));
    m2.insert(pair<int,int>(88,80));
    m2.insert(pair<int,int>(99,90));
    printMap(m2);
    cout<<"size="<<m2.size()<<endl;
    cout<<"empty="<<m2.empty()<<endl;
    
    cout<<"swap later"<<endl;
    m1.swap(m2);
    printMap(m1);
    cout<<endl;
    printMap(m2);
    
}
//map插入和删除

void test3(){
    map<int,int> m1;
    m1.insert(pair<int,int>(1,10));
    
    m1.insert(make_pair(2,20));
    m1.insert(map<int,int>::value_type(3,30));
    m1[4]=40;
    printMap(m1);
     
    m1.erase(3);
    printMap(m1);

    m1.erase(m1.begin(),m1.end());
    m1.clear();
    printMap(m1);

}

//map查找和统计

void test4(){
    map<int,int> m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    m1.insert(pair<int,int>(5,50));
    m1.insert(pair<int,int>(6,60));
    m1.insert(pair<int,int>(7,70));
    m1.insert(pair<int,int>(8,80));
    m1.insert(pair<int,int>(9,90));
    m1.insert(pair<int,int>(10,100));
    map<int,int>::iterator pos=m1.find(5);
    if(pos!=m1.end()){
        cout<<"key="<<pos->first<<" value="<<pos->second<<endl;
    }else{
        cout<<"not found"<<endl;
    }

    int num=m1.count(7);
    cout<<"num="<<num<<endl;
}

//map排序
class myCompare{
    public:
        bool operator()(int v1,int v2)const{
            return v1>v2;
        }
};

void test5(){
    map<int,int,myCompare> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    m.insert(pair<int,int>(5,50));
    m.insert(pair<int,int>(6,60));
    for(map<int,int,myCompare>::iterator it=m.begin();it!=m.end();it++){
        cout<<"key="<<it->first<<" value="<<it->second<<endl;
    }
}

int main(){
    test5();
    return 0;
}