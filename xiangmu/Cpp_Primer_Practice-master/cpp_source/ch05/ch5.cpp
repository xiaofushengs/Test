//
// Created by cer on 17-9-18.
// chapter 5
// 语句

#include <iostream>
#include <vector>
using namespace std;

// int divide(int a, int b){
//     if (b == 0){
//         // 抛出异常
//         throw runtime_error("b cannot be 0!");
//     }
//     else{
//         return a / b;
//     }
// }

// int main(){
//     int a = 1, b = 0, res;
//     try{
//         res = divide(a, b);
//         cout << res << endl;
//     }catch(runtime_error err){
//         cout << err.what() << endl;
//     }
//     return 0;
// }

// class DivideByZeroException : public exception {
// public:
//     // 重写 what() 函数，返回异常信息
//     const char* what() const noexcept override {
//         return "Attempt to divide by zero";
//     }
// };

// int divide(int a, int b){
//     if(b==0){
//         throw DivideByZeroException(); 
//     }
//     return a / b;
// }

// void test(){
//     int a = 1, b = 0, res;
//     try{
//         res = divide(a, b);
//         cout << res << endl;
//     }catch(int error){
        
//     }
//     cout << "hello world" << endl;

// }
// int main(){
//     test();
//     return 0;
// }




void fun(int a){
    if(a==0){
        throw 2;
    }
}
void test(){
    try{
        fun(0);
    }catch(int a){
        cout << a << endl;
    }catch(...){
        cout << "hello world" << endl;
    }
}


int main(){
    test();
    return 0;
}


