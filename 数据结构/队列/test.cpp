#include "QueueManager.h"

int main(){
    QueueLinkedList<int> q;
    cout<<q.getsize()<<endl;
    for (int i = 0; i < 10; i++)
    {
        q.enqueue(i*10);
    }
    cout<<q.Top()<<endl;
    cout<<q.back()<<endl;

    cout<<"-----"<<endl;
    while(!q.isEmpty()){
        cout<<q.Top()<<" "<<q.getsize()<<endl;
        q.dequeue();
    }



    
}