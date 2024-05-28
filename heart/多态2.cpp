#include<iostream>
#include<string>
using namespace std;

//����������Ʒ
class AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//�涨����
	void MakeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class Coffee : public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() {
		cout << "��ũ��ɽȪ!" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݿ���!" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "�����ȵ��뱭��!" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "����ţ��!" << endl;
	}
};

//������ˮ
class Tea : public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil() {
		cout << "������ˮ!" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ!" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "����ˮ���뱭��!" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "�������!" << endl;
	}
};

//ҵ����


void test01() {
	AbstractDrinking *coffee=new Coffee;
    coffee->MakeDrink();
    cout << "--------------" << endl;
	cout << "--------------" << endl;
    AbstractDrinking *tea=new Tea;
    tea->MakeDrink();
	
}


int main() {

	test01();

	system("pause");

	return 0;
}