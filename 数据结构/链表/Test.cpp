#include "LinkManager.h"

int main(){
    LinkedList<int> li;
    li.DeleteNode(5);
    for (int i = 0; i < 10; i++)
    {
        li.Insert(i);
    }
    li.printLinkedlist();
    cout<<"数组长度："<<li.Getsize()<<endl;
    li.DeleteNode(5);
    
    li.printLinkedlist();
    cout<<"数组长度："<<li.Getsize()<<endl;
    return 0;
}