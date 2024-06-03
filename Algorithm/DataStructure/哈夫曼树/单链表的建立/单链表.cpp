#include <iostream>
using namespace std;

class Single_List{
	private:
		int data;
		Single_List* next;
	public:	
		//������Ĵ�������
		Single_List* Create(int len){
			cout<<"������Ҫ����������ֵ��"<<endl;
			Single_List* prev;
			Single_List* head;
			Single_List* tail;
			head = new Single_List;
			head->data = len;
			head->next = NULL;
			prev = head;
			while(len--){
				tail = new Single_List;
				cin>>tail->data;
				tail->next = NULL;
				prev->next = tail;
				prev = tail;
			}
			return head;
		}
		
		bool Isempty(){
			return this->data == 0;
		}
		
		//������Ĵ�ӡ����
		void Print(Single_List* list){
			if(list->Isempty()){
				cout<<"������Ϊ��"<<endl;
				return;
			}
			int len = list->data;
			Single_List* ptrl = list->next;
			for(int i = 0 ; i < len ; i++){
				cout<<ptrl->data<<" ";	
				ptrl = ptrl->next;
			}
		} 
};

int main()
{
	cout<<"�������ʼ��������ĳ���:"<<endl;
	int len;
	Single_List tmp; 
	Single_List* list;
	cin>>len;
	list = tmp.Create(len);
	
	cout<<"���������£�"<<endl; 
	tmp.Print(list);
	cout<<endl;	
	
	return 0;
 } 
