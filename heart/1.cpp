#include<iostream>
using namespace std;

int *fun(){
    int *a=new int(10);
    return a;
}
void test(){
    int *p=fun();
    cout<<*p<<endl;
    cout<<p<<endl;
    cout<<fun()<<endl;
    cout<<*fun()<<endl;
    
    delete p;

}


void test1(){
    int a=10;
    int *p=&a;
    cout<<*p<<endl;
    cout<<p<<endl;
    *p=20;
    cout<<*p<<endl;
    cout<<a<<endl;
}


void test2(){
    int *arr=new int[10];
    for(int i=0;i<10;i++){
        arr[i]=i;
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<10;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;

    
    delete[] arr;
}


void test3(){
    int a=10;
    int b=20;
    int &c=a;
    c=b;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;

    cout<<"a的地址:"<<&a<<endl;
    cout<<"b的地址:"<<&b<<endl;
    cout<<"c的地址:"<<&c<<endl;
}

void test4(){
    int a=10,b=20;
    int *p=&a;
    
    cout<<&a<<endl;
    cout<<&b<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    p=&b;
    cout<<&a<<endl;
    cout<<&b<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    
}

void swap(int a, int b){
    cout<<&a<<a<<endl;
    cout<<&b<<b<<endl;
    int temp=a;
    a=b;
    b=temp;
    cout<<&temp<<temp<<endl;
    cout<<&a<<a<<endl;
    cout<<&b<<b<<endl;
}
void swap1(int *a, int *b){
    cout<<a<<" "<<*a<<endl;
    cout<<b<<" "<<*b<<endl;
    int temp=*a;
    *a=*b;
    *b=temp;
    cout<<&temp<<" "<<temp<<endl;
    cout<<a<<" "<<*a<<endl;
    cout<<b<<" "<<*b<<endl;
}
void test5(){
    int a=10,b=20;
    cout<<&a<<" "<<a<<endl;
    cout<<&b<<" "<<b<<endl;
    cout<<endl;
    swap1(&a,&b);
    cout<<endl;
    cout<<&a<<" "<<a<<endl;
    cout<<&b<<" "<<b<<endl;
}


int& test01() {
	int a = 10; //局部变量
	return a;
}

//返回静态变量引用
int& test02() {
	static int a = 20;
	return a;
}
void test6(){
    //不能返回局部变量的引用
	// int& ref = test01();
	// cout << "ref = " << ref << endl;
	// cout << "ref = " << ref << endl;

	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;
}


void fun(int& ref){
    ref=100;
}
void test7(){
    int a=10;
    int &ref=a;
    cout<<&a<<" "<<a<<endl;
    
    cout<<&ref<<" "<<ref<<endl;
    fun(a);
    cout<<&a<<" "<<a<<endl;
    cout<<&ref<<" "<<ref<<endl;

}

void showValue(const int& v){
    cout<<v<<endl;
}

void test8(){
    const int& ref=10;
    cout<<ref<<endl;

    int a=100;
    showValue(a);
}


int main(){
    test8();
    return 0;
}