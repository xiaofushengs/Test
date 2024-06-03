#include <iostream>
#include <vector>
using namespace std;

struct node{
	int data;
	struct node* next;	
};

typedef struct node Node;

class HashTable{
	private:
		vector<Node*> nodes;
		int length;
		int Max_Prime;
	public:
		//���캯��
		HashTable(int length){
			this->length = length;
			nodes.reserve(this->length);
			this->Max_Prime = this->getMaxPrime();
			for(int i = 0 ; i < this->length ; i++){
				this->nodes.push_back(this->Create_Node(i));
			}
		}
		
		Node* Create_Node(int num){
			Node* node = new Node;
			node->data = num;
			node->next = NULL;
			return node;
		}
		
		//�ж��������� 
		bool isPrime(int num){
			bool flag = true;
			if(num <= 1){
				flag = false;
			}else if( num == 2){
				flag = true;
			}else{
				for(int i = 2 ; i < num-1 ; i++){
					//num�ܱ�i���� 
					if(num % i == 0){
						flag = false;
						break; 
					}
				}
			}
			return flag;
		}
		
		//Ѱ��С�ڱ����������
		int getMaxPrime(){
			for(int i = this->length-1 ; i >= 0 ; i--){
				if(this->isPrime(i)){
					return i;
				}
			}
		}
		
		//hash����
		int hash(int num){
			return num % this->Max_Prime;
		}
		
		Node* Attach(Node* node1 ,Node* node2){
			Node* cur = node1;
			while(1){
				if(cur->next == NULL){
					cur->next = node2;
					break;
				}
				cur = cur->next;
			}
			return node1;
		}
		
		//���뺯�� 
		void Insert(int num){
			//���������ڵĵ�ַ 
			int index = this->hash(num);
			//������� 
			Node* node = NULL;
			node = this->Create_Node(num); 
			//�ѽ�����ӵ����ʵĵ�ַ����� 
			Node* tmp = NULL;
			tmp = this->nodes[index];
			this->nodes[index] = this->Attach(tmp,node);
		} 
		
		//������
		void Create(int size,int* num){
			for(int i = 0 ; i < size ; i++){
				//������
				this->Insert(num[i]);
			}
		}
		
		//ɾ�����
		bool Delete(int num){
			int index = this->hash(num);
			Node* cur = this->nodes[index];
			while(cur->next->data != num){
				cur = cur->next;
			}
			if(cur == NULL){//�ڹ�ϣ����δ�ҵ�num 
				return false;
			}
			Node* tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
			return true; 
		}
		
		void Print_List(Node* node){
			Node* cur = node;
			while(cur){
				cout<<cur->data<<" ";
				cur = cur->next; 
			}
		}
		
		//���Һ��� 
		int Find(int num){
			int index = this->hash(num);
			Node* cur = this->nodes[index];
			while(cur->data != num){
				cur = cur->next;
			}
			if(cur == NULL){//��ϣ����û��num 
				index = -1;
			}
			return index;
		}
		
		//��ӡ����
		void Print(){
			cout<<"�±�\tԪ�أ�"<<endl;
			for(int i = 0 ; i < this->nodes.size() ; i++){
				if(this->nodes[i]->next != NULL){
					cout<<i<<":\t";
					this->Print_List(this->nodes[i]->next);
					cout<<endl; 
				}
			}
		} 
};

int main()
{
	cout<<"�������ϣ���ȣ�"<<endl;
	int length;
	cin>>length;
	cout<<"��������Ҫ�����Ԫ�ظ�����"<<endl;
	int size;
	int* data;
	cin>>size;
	data = new int[size];
	cout<<"���ʼ��Ԫ�أ�"<<endl;
	for(int i = 0 ; i < size ; i++){
		cin>>data[i];
	}
	
	HashTable hashtable(length); 
	hashtable.Create(size,data);
	cout<<"��ϣ��Ϊ��"<<endl;
	hashtable.Print();
	
	int num,index;
	cout<<"������ҪѰ�ҵ�Ԫ�أ�"<<endl;
	cin>>num;
	index = hashtable.Find(num);
	if(index == -1){
		cout<<"��ϣ����û��"<<num<<"���Ԫ��"<<endl; 
	}else{
		cout<<num<<"�ڵ�ַΪ"<<index<<"��ָ���������"<<endl; 
	}
	
	cout<<"������Ҫ�����Ԫ�أ�"<<endl;
	cin>>num;
	cout<<"����ǰ��ϣ��Ϊ��"<<endl;
	hashtable.Print(); 
	cout<<"������ϣ��Ϊ��"<<endl;
	hashtable.Insert(num);
	hashtable.Print();
	 
	cout<<"������Ҫɾ����Ԫ�أ�"<<endl;
	cin>>num;
	cout<<"ɾ��ǰ��ϣ��Ϊ��"<<endl;
	hashtable.Print(); 
	cout<<"ɾ�����ϣ��Ϊ��"<<endl;
	hashtable.Delete(num);
	hashtable.Print();
	
	return 0;
 } 
