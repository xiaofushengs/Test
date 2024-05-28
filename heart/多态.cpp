#include<iostream>

using namespace std;

class Animal
{
public:
	//Speak���������麯��
	//����ǰ�����virtual�ؼ��֣�����麯������ô�������ڱ����ʱ��Ͳ���ȷ�����������ˡ�
	virtual void speak()=0;
	
};

class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal
{
public:

	void speak()
	{
		cout << "С����˵��" << endl;
	}

};
//����ϣ������ʲô������ô�͵���ʲô����ĺ���
//���������ַ�ڱ���׶ξ���ȷ������ô��̬����
//���������ַ�����н׶β���ȷ�������Ƕ�̬����


//
//��̬���������� 
//1���м̳й�ϵ
//2��������д�����е��麯��
//��̬ʹ�ã�
//����ָ�������ָ���������

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