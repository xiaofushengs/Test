#include<iostream>
#include<stack>

using namespace std;

class Myqueue{
    public:
        stack<int> input;
        stack<int> output;

        void Push(int val){
            input.push(val);
        }

        int Pop(){
            if(output.empty()){
                while (!input.empty())
                {
                    output.push(input.top());
                    input.pop();
                }
            }
            int result=output.top();
            output.pop();
            return result;
        }

        bool empty(){
            return input.empty() && output.empty();
        }

        int Peek(){
           int res=this->Pop();
           output.push(res);
           return res;
        }
    
};


int main(){
    Myqueue queue;
    for (int i = 0; i < 10; i++)
    {
        queue.Push(i);
    }

    while (!queue.empty())
    {
        cout<<queue.Peek()<<" ";
        queue.Pop();
    }
    cout<<endl;
    

    return 0;
}