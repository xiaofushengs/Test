#include<iostream>
#include<string>
#include<cmath>

using namespace std;


void fun(const string& str){
    cout<<str<<endl;
}
void test(){
     string str="hello,world";
     fun(str);
}

class Circle{
    
    public:
        Circle(double radius){
        this->r=radius;
        }
        void Zhou(){
            double z=r*2*M_PI;
            cout<<"�ܳ�Ϊ��"<<z<<endl;
        }
        void Area(){
            double s=r*r*M_PI;
            cout<<"���Ϊ��"<<s<<endl;
        }
        double r;
};

void test2(){
    Circle c(10);
    c.Zhou();
    c.Area();

}

int main(){
    // test();
    test2();
    return 0;
}