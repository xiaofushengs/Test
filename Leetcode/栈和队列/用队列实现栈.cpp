#include<iostream>
#include<queue>

using namespace std;

class Mystack{
    public:
        queue<int> que1;
        queue<int> que2;

        void push(int val){
            que1.push(val);
        }

        int pop(){
            int size=que1.size()-1;
            while (size--)
            {
                que2.push(que1.front());
                que1.pop();
            }

            int result=que1.front();
            que1.pop();
            que1=que2;
            while (!que2.empty())
            {
                que2.pop();
            }
            return result;
        }

        int top(){
            return que1.back();
        }

        bool empty(){
            return que1.empty();
        }


};
int main(){
    Mystack s;
    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}