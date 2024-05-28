#include<iostream>
#include<string>
#include<list>

using namespace std;

// push_back(elem);//在容器尾部加入一个元素
// pop_back();//删除容器中最后一个元素
// push_front(elem);//在容器开头插入一个元素
// pop_front();//从容器开头移除第一个元素
// insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
// insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
// insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
// clear();//移除容器的所有数据
// erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
// erase(pos);//删除pos位置的数据，返回下一个数据的位置。
// remove(elem);//删除容器中所有与elem值匹配的元素
void printList(const list<int> &l){
    for(list<int>::const_iterator it=l.begin();it!=l.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test(){
    list<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    list1.push_front(100);
    list1.push_front(200);
    list1.push_front(300);
    printList(list1);

    //尾delelte
    list1.pop_back();
    printList(list1);
    //头delelte
    list1.pop_front();
    printList(list1);
    //insert
    list<int>::iterator it=list1.begin();
    list1.insert(++it,1000);
    printList(list1);
    list<int>::iterator it1=list1.begin();
    list1.insert(it1++,2,2000);
    printList(list1);

    //删除
    list<int>::iterator it2=list1.begin();
    list<int>::iterator it3=list1.begin();
    for(int i=0;i<3;i++){
        ++it2;
        it3=it2;
    }
    list1.erase(it2,++it3);
    printList(list1);

    //remove
    list1.remove(2000);
    printList(list1);

    //clear
    list1.clear();
    printList(list1);

    

    
}

//数据存取
void test1(){
    list<int> list1;
    for(int i=0;i<10;i++){
        list1.push_front(i);
    }
    printList(list1);
    cout<<"front:"<<list1.front()<<endl;
    cout<<"back:"<<list1.back()<<endl;
    cout<<"size:"<<list1.size()<<endl;
    cout<<"empty:"<<list1.empty()<<endl;


}

//list反转和排序
// reverse(); //反转链表
// sort(); //链表排序

bool mycompare(int v1,int v2){
    return v1>v2;
}
void test2(){
    list<int> list1;
    for(int i=0;i<10;i++){
        list1.push_front(i);
    }
    for(int i=10;i>0;i--){
        list1.push_back(i*10);
    }
    printList(list1);
    //反转
    list1.reverse();
    printList(list1);

    //排序
    list1.sort();
    printList(list1);

    //排序
    list1.sort(mycompare);
    printList(list1);


    

}
int main(){
    test2();
    return 0;
}