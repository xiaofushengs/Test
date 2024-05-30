#include"DoublyLinkedList.h"

int main(){
    DoublyLinkedList<int> list;
    for (int i = 0; i < 10; i++)
    {
        list.InsertBack(i);
    }
    list.printAllBackward();
    list.InsertFront(100);
    list.printAllBackward();
    list.remove(100);
    list.remove(9);
    list.printAllBackward();
    list.printAllForward();


}