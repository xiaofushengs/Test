#include <iostream>
using namespace std;

class Double_List{
	private:
		int data;
		Double_List* next;
		Double_List* prior;
	public:
		//N������˫����Ĺ������� 
		Double_List* Create(int N){
			//��ʼ��ͷ��㣬ͷ��㱣�������� 
			Double_List* head;
			head= new Double_List;
			head->data = N;
			head->prior = NULL;
			head->next = NULL;
			//pre�����һ����ֵ��㣬tail����Ҫ����Ľ��
			//tmp��pre�ı��ݣ����ڸı䵱ǰָ�� 
			Double_List* pre,*tail,*tmp;
			pre = new Double_List;
			int data;
			cout<<"���ʼ��ÿ��������ֵ��"<<endl; 
			//��ʼ��ͷ����ֵ���
			cin>>pre->data;
			pre->next = NULL;
			pre->prior = NULL;
			tmp = pre;
			N--;
			//ʣ��Ľ���ʼ�� 
			while(N--){
				tail = new Double_List;
				cin>>tail->data;
				this->attach(tmp,tail);
				tmp = tail;
			}
			pre->prior = head;
			head->next = pre;
			return head; 
		}
		
		//�����������Ӻ��� 
		void attach(Double_List* pre, Double_List* tail){
			pre->next = tail;
			tail->next = NULL;
			tail->prior = pre; 
		} 
		
		//˫����Ĵ�ӡ���� 
		void Print(Double_List* list){
			int len = list->data;
			Double_List* head;
			head = list->next;
			for(int i = 0 ; i < len ; i++){
				cout<<head->data<<" ";
				head = head->next;
			}
		}
		
		//˫����ĳ��Ⱥ��� 
		int GetLength(Double_List* list){
			return list->data;
		}
		
		//�ж�˫�����Ƿ�Ϊ��
		bool Isempty(Double_List* list){
			return this->GetLength(list) == 0;
		} 
		
		//Ѱ��˫�����е�k�����ĺ��� 
		Double_List* FindKth(Double_List* list,int index){
			Double_List* head;
			head = list;
			for(int i = 0 ; i < index ; i++){
				head = head->next;
			}
			return head;
		} 
		
		//Ѱ����ֵΪN�Ľ����±�ĺ���
		int FindN(Double_List* list,int N){
			//-1��ʾֵΪN�Ľ�㲻���� 
			int result = -1;
			Double_List* prev;
			prev = list;
			int len = this->GetLength(list); 
			for(int i = 0 ; i < len ; i++){
				prev = prev->next;
				if(prev->data == N){
					result = i;
					break;
				}
			}
			return result; 
		} 
		
		//��forward�������һ��insert���ĺ��� 
		void Insert(Double_List* forward,Double_List* insert){
			insert->next = forward->next;
			//������λ�ò�������β��ʱ 
			if(forward->next != NULL){
				forward->next->prior = insert;
			} 
			forward->next = insert;
			insert->prior = forward;
		} 
		
		//˫�������ֵΪk�Ľ��֮����뺯��
		Double_List* Insert_num(Double_List* list,int num){
			int index = this->FindN(list,num);
			//˫�����в�����ֵΪnum�Ľ������ 
			if(index == -1){
				cout<<"˫������û��ֵΪ��"<<num<<"�Ľ��"<<endl;
				return list;
			}
			return this->Insert_index(list,index+1);
		}
		
		//˫������ڵ�k�����֮����뺯��
		Double_List* Insert_index(Double_List* list,int index){
			cout<<"���ʼ�����:"<<endl;
			Double_List* insert;
			insert = new Double_List;
			cin>>insert->data;
			//����Ϊ��ʱ 
			if(this->Isempty(list)){
				insert->next = NULL;
				list->next = insert;
				insert->prior = list;
				list->data++;			
				return list;
			}
			//�����±������������ȣ�ֱ�Ӳ嵽����β�� 
			index = (index <= this->GetLength(list))?index:this->GetLength(list);
			Double_List* forward;
			forward = this->FindKth(list,index);
			this->Insert(forward,insert); 
			list->data++;
			return list;
		}
		
		void Delete(Double_List* forward,Double_List* _delete){
			forward->next = _delete->next;
			if(_delete->next != NULL){
				_delete->next->prior = forward;
			} 
			 delete _delete; 
		}
		
		//ɾ��ֵΪnum�Ľ�� 
		Double_List* Delete_num(Double_List* list, int num){
			int index = this->FindN(list,num);
			//˫�����в�����ֵΪnum�Ľ������ 
			if(index == -1){
				cout<<"˫������û��ֵΪ��"<<num<<"�Ľ��"<<endl;
				return list;
			}
			return this->Delete_index(list,index+1);
		}
		
		//ɾ����index�����ĺ��� 
		Double_List* Delete_index(Double_List* list, int index){
			//�����±������������ȣ�ֱ��ɾ������β�����
			index = (index<this->GetLength(list))?index:this->GetLength(list);
			Double_List* forward = this->FindKth(list,index-1);
			Double_List* _delete = forward->next;
			this->Delete(forward,_delete);
			list->data--;
			return list;
		}
		
		//��ת����
		Double_List* Reverse(Double_List* list){
			Double_List* head,*front,*tail,*tag;
			head = list;
			front = list->next;
			tail = front->next;
			front->next = NULL;
			while(tail){
				tag = tail->next;
				tail->next = front;
				front->prior = tail;
				front = tail;
				tail = tag;
			}
			head->next = front;
			front->prior = head;
			return head;
		}
		
		//��������ð������
		Double_List* Sort(Double_List* list){
			Double_List* head,*prev1,*prev2;
			head = list;
			prev1 = list->next;
			while(prev1){
				prev2 = prev1->next;
				while(prev2){
					if(prev1->data > prev2->data){
						prev1->data += prev2->data;
						prev2->data = prev1->data - prev2->data;
						prev1->data -= prev2->data;
					}	
					prev2 = prev2->next;
				}
				prev1 = prev1->next;
			}
			return head;
		}
};

int main()
{
	Double_List tmp;
	Double_List* list;
	int len,index,num;
	cout<<"���ʼ��˫����ĳ��ȣ�"<<endl;
	cin>>len; 
	list = tmp.Create(len);
	list = tmp.Sort(list);
	cout<<"˫����Ϊ��"<<endl;
	tmp.Print(list);
	cout<<endl;
	
	cout<<"����ǰ˫����Ϊ��"<<endl; 
	tmp.Print(list); 
	cout<<endl<<"��������Ҫ����֮�����������:"<<endl;
	cin>>index;
	list = tmp.Insert_index(list,index);
	cout<<"�����˫����Ϊ��"<<endl; 
	tmp.Print(list); 
	cout<<endl;
	
	cout<<"����ǰ˫����Ϊ��"<<endl; 
	tmp.Print(list); 
	cout<<endl<<"��������Ҫ����֮����������ֵ:"<<endl;
	cin>>num;
	list = tmp.Insert_num(list,num);
	cout<<"�����˫����Ϊ��"<<endl; 
	tmp.Print(list);
	cout<<endl;
	
	cout<<"ɾ��ǰ˫����Ϊ��"<<endl; 
	tmp.Print(list); 
	cout<<endl<<"��������Ҫ����֮��ɾ���������:"<<endl;
	cin>>index;
	list = tmp.Delete_index(list,index);
	cout<<"ɾ����˫����Ϊ��"<<endl; 
	tmp.Print(list); 
	cout<<endl;
	
	cout<<"ɾ��ǰ˫����Ϊ��"<<endl; 
	tmp.Print(list); 
	cout<<endl<<"��������Ҫ����֮��ɾ��������ֵ:"<<endl;
	cin>>num;
	list = tmp.Delete_num(list,num);
	cout<<"ɾ����˫����Ϊ��"<<endl; 
	tmp.Print(list);
	cout<<endl;
	
	cout<<"��ת˫��������ǰ,˫�������£�"<<endl;
	tmp.Print(list);
	cout<<endl<<"��ת˫�����,˫�������£�"<<endl;
	list = tmp.Reverse(list); 
	tmp.Print(list); 
	
	return 0;
 } 
