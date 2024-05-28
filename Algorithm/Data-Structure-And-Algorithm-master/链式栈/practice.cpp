#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 0xffff

template<typename T>
class my_stack
{
    int top;
    T* my_s;
    int maxsize;

public:
    my_stack():top(-1),maxsize(MAXSIZE)
    {
        my_s=new T[maxsize];
        if(my_s==NULL)
        {
            cerr<<"????????!"<<endl;
            exit(1);
        }
    }
    my_stack(int size):top(-1),maxsize(size)
    {
        my_s=new T[maxsize];
        if(my_s==NULL)
        {
            cerr<<"????????!"<<endl;
            exit(1);
        }
    }
    ~my_stack()
    {
        delete[] my_s;
    }
    //????
    bool Empty();
    //??
    void Push(T tp);
    //??????
    T Top();
    //??
    void Pop();
    //???
    int Size();
};

template<typename T>
bool my_stack<T>::Empty()
{
    if(top==-1){
        return true;
    }
    else
        return false;
}

template<typename T>
T my_stack<T>::Top()
{
    if(top!=-1)
    {
        return my_s[top];
    }
    else
    {
        cout<<"??\n";
        exit(1);
    }
}

template<typename T>
void my_stack<T>::Push(T tp)
{
    if(top+1<maxsize)
    {
        my_s[++top]=tp;
    }
    else
    {
        cout<<"??\n";
        exit(1);
    }
}

template<typename T>
void my_stack<T>::Pop()
{
    if(top>=0)
    {
        top--;
    }
    else
    {
        cout<<"??\n";
        exit(1);
    }
}

template<typename T>
int my_stack<T>::Size()
{
    return top+1;
}
