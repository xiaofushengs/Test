#include<iostream>
#include<string>
#include<list>

using namespace std;

// 链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的

// 链表的组成：链表由一系列结点组成

// 结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域

// STL中的链表是一个双向循环链表

void printList(const list<int> &l){
    for(list<int>::const_iterator it = l.begin(); it!= l.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void test(){
    list<int> L1;
    for(int i = 1; i < 10; ++i){
        L1.push_back(i*10);
    }
    printList(L1);

    list<int> L2(L1);
    printList(L2);

    list<int> L3(L1.begin(), L1.end());
    printList(L3);

    list<int> L4(10, 100);
    printList(L4);
}
//赋值和交换
// assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
// assign(n, elem); //将n个elem拷贝赋值给本身。
// list& operator=(const list &lst); //重载等号操作符
// swap(lst); //将lst与本身的元素互换。
void test2(){
    list<int> L1;
    for(int i = 10; i > 0; --i){
        L1.push_back(i*10);
    }
    printList(L1);

    list<int> L2;
    L2.assign(L1.begin(), L1.end());
    printList(L2);

    list<int> L3;
    L3.assign(10, 100);
    printList(L3);

    L1.swap(L3);
    printList(L1);
    printList(L3);


}

//list 大小操作
// 判断是否为空 --- empty
// 返回元素个数 --- size
// 重新指定个数 --- resize
void test3(){
    list<int> L1;
    for(int i = 10; i > 0; --i){
        L1.push_back(i*10);
    }
    printList(L1);

    if(L1.empty()){
        cout << "L1 is empty" << endl;
    }
    else{
        cout << "L1 is not empty" << endl;
        cout << "L1 has " << L1.size() << " elements" << endl;
    }

    L1.resize(5);
    printList(L1);

    L1.resize(15, 100);
    printList(L1);
}
int main() {
    test3();
    return 0;
}

