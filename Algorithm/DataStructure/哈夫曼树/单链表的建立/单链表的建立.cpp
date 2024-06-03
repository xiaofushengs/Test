#include <iostream>
using namespace std;

typedef struct Code* code;
struct Code
{
	int data;
	code next;
};

class List
{
	private:
		Code list;
	public:
		code Create_List();									//���������� 
		code Insert_List(code ptrl);						//�ڵ�index��λ�ú����Ԫ�� 
		void Print_List(code ptrl);							//��ӡ������ 
		code Delete_List(code ptrl);						//ɾ����index��λ���ϵ�Ԫ�� 
		int List_length(code ptrl);							//������ĳ��� 
};

code List::Create_List()
{
	int N;
	cout<<"�����뵥����ĳ�ʼ�ڵ���:";
	cin>>N;
	cout<<"����������:\n";
	code head,prev,curren,tmp;
	head = new struct Code;
	head->next = NULL;				//��� 
	prev = head;					//*prevָ��ͷ��� 
	while(N--)
	{
		curren = new struct Code;
		cin>>curren->data;
		curren->next = NULL;		//*curren����� 
		//β�巨 ԭ�ڵ�β������curren��� 
		prev->next = curren;
		prev = curren; 
	 } 
	 prev = head->next;
	 
	 return prev;
}

code List::Insert_List(code ptrl)
{
	int list_length = List_length(ptrl);
	cout<<"�������������ݵ�λ��:";
	int index;
	cin>>index;
	cout<<"��������Ϊ:"<<list_length<<endl;
	cout<<"��������������:";
	int n;
	cin>>n; 
	int i;
	code p,s,ptrl0;
	ptrl0 = ptrl;
	if ( index == 0 )
	{
		p = new struct Code;
		p->data = n;
		s = p;
		p->next = ptrl;
		ptrl = s;
		ptrl0 = ptrl;
	}
	else
	{
		if ( index<= list_length )
		{
			for ( i = 1 ; i < index ; i++ )
			{
				ptrl = ptrl->next;
			 } 
			 p->data = n;
			 p->next = ptrl->next;
			 ptrl->next = p;
		}
		else
		{
			cout<<"���λ�ò��Ǳ�β�ĺ�һ��λ��,�˴�ֻ�ܲ��뵽��β����\n";
			for ( i = 1 ; i < list_length ; i++ )
			{
				ptrl = ptrl->next;
			}
			p->data = n;
			p->next = ptrl->next;
			ptrl->next = p;
		}
	}
	return ptrl0;
}

int List::List_length(code ptrl)
{
	int count = 0;
	code p;
	for ( p = ptrl ; p!=NULL; p = p->next)
			count++;
	return count;
}

code List::Delete_List(code ptrl)
{
	int index;
	cout<<"��������ɾ��Ԫ�ص�λ��:";
	cin>>index;
	int list_length = List_length(ptrl);
	int i;
	code tmp,ptrl0;
	ptrl0 = ptrl;
	cout<<"��������Ϊ:"<<list_length<<endl;
	if ( index > list_length )
	{
		cout<<"���λ�ò��Ϸ���"<<endl;
	}
	else
	{
		if ( index == 1 )
		{
			tmp = ptrl;
			ptrl = ptrl->next;
			ptrl0 = ptrl;
			delete tmp;
		}
		else
		{
			for ( i = 1 ; i < index-1 ;i++ )
			{
				ptrl = ptrl->next;
			 } 
			tmp = ptrl->next;
			ptrl->next = (ptrl->next)->next;
			delete tmp;
		}
	}
	return ptrl0;
 } 

void List::Print_List(code ptrl)
{
	code p;
	cout<<"���������:\n";
	for( p = ptrl;p!=NULL;p = p->next)
		cout<<p->data<<endl;
}

int main()
{
	List list;
	code ptrl;
	//��ʼ�������� 
	ptrl = list.Create_List();
	list.Print_List(ptrl);
	
	//�ڵ�n��λ��֮��������� 
	ptrl=list.Insert_List(ptrl);
	list.Print_List(ptrl);
	
	//ɾ����n��λ���ϵ�Ԫ��
	ptrl=list.Delete_List(ptrl);
	list.Print_List(ptrl);
	
	return 0;
 } 
