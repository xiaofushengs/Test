#include "StackManager.h"

int main(){
    StackLinkedList<int>  s;
    for (int i = 0; i < 10; i++)
    {
        s.Push(i);
    }
    while(!s.isEmpty()){
        cout<<s.Top()<<" ";
        cout<<s.getsize()<<endl;
        s.Pop();
    }

    return 0;
    
}