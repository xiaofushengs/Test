#include<iostream>

using namespace std;

class Animal
{
public:
	//Speak函数就是虚函数
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	virtual void speak()=0;
	
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:

	void speak()
	{
		cout << "小狗在说话" << endl;
	}

};
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编


//
//多态满足条件： 
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象

void test01()
{
	Animal *cat=new Cat;
    cat->speak();
    delete cat;
    Animal *dog=new Dog;
    dog->speak();
    delete dog;
}


class Abstractcalculator{
    public:
        virtual int getrult(){
            return 0;
        }
        
        int m_num1;
        int m_num2;
};
class addcalculator:public Abstractcalculator{
    public:
    int getrult(){
        return m_num1+m_num2;
    }
};

class subcalculator:public Abstractcalculator{
    public:
    int getrult(){
        return m_num1-m_num2;
    }
};

class mulcalculator:public Abstractcalculator{
    public:
    int getrult(){
        return m_num1*m_num2;
    }
};

class divcalculator:public Abstractcalculator{
    public:
    int getrult(){
        return m_num1/m_num2;
    }
};


void test02(){
    Abstractcalculator *abc=new addcalculator;
    abc->m_num1=10;
    abc->m_num2=20;
    cout<<abc->getrult()<<endl;
    delete abc;
    abc=new subcalculator;
    abc->m_num1=10;
    abc->m_num2=20;
    cout<<abc->getrult()<<endl;
    delete abc;
    abc=new mulcalculator;
    abc->m_num1=10;
    abc->m_num2=20;
    cout<<abc->getrult()<<endl;
    delete abc;
    abc=new divcalculator;
    abc->m_num1=10;
    abc->m_num2=20;
    cout<<abc->getrult()<<endl;
    delete abc;
}


int main() {
    test01();
	test02();

	system("pause");

	return 0;
}