#include <iostream>
#include <cmath> 
#include <cstring> 
using namespace std;

const int MAX = 65535;

class HashTable{
	private:
		int length;		//��ϣ��� 
		int size;		//��ϣ�����Ѿ������Ԫ�� 
		int* data;		//Ԫ�ر�
		int Max_Prime;	//������� 
		int* delete_flag;	//ɾ����־ 
	public:
		//���캯��
		HashTable(int length){
			this->length = length;
			this->data = new int[this->length];
			this->Max_Prime = this->getMaxPrime(); 
			this->delete_flag = new int[this->length];
			memset(this->delete_flag,0,sizeof(this->delete_flag[0])*this->length);
			for(int i = 0 ; i < this->length ; i++){
				//��ʼ�����ֵ����ʾδ���� 
				this->data[i] = MAX;		 
			}
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
			return num%this->Max_Prime;
		}
		
		//���뺯��,��������̽�ⷨ 
		bool Insert_Linear_Probing(int num){
			//��ϣ���Ѿ���װ������������ 
			if(this->size == this->length){
				return false;
			}
			int index = this->hash(num);
			if(this->data[index] == MAX){
				this->data[index] = num;
			}else{
				int i = 1;
				//Ѱ�Һ���λ�� 
				while(this->data[(index+i)%this->length] != MAX){
					i++;
				}
				index = (index+i)%this->length; 
				this->data[index] = num;
			}
			if(this->delete_flag[index] == 1){//֮ǰ����Ϊɾ�� 
				this->delete_flag[index] = 0; 
			}
			this->size++;
			return true;
		}
		
		//������
		void Create_Linear_Probing(int* num , int size){
			for(int i = 0 ; i < size ; i++){
				this->Insert_Linear_Probing(num[i]);
			}
		}
		
		//���Һ��� 
		int Find_Linear_Probing(int num){
			int flag = -1;
			int index = this->hash(num);
			if(this->data[index] == num && this->delete_flag[index] == 0){
				flag = index;
			}else{
				int i = 1;
				while(1){
					if(this->delete_flag[index+i] == 0){//δ����Ϊ��ɾ�� 
						if(this->data[index+i] != num){
							//�����������,Ҳ������num,��ƫ������1 
							i++;
						}else{//����numʱ 
							flag = index+i;
							break;
						}	
					}else{//����Ϊ��ɾ�� 
						i++;
					} 
				}
			}
			return flag; 
		}
		
		//����̽���ɾ������
		bool Delete_Linear_Probing(int num){
			int index = this->Find_Linear_Probing(num);
			if(index == -1){
				return false;
			}else{
				this->delete_flag[index] = 1;//����Ϊ��ɾ�� 
				this->size--; 
				return true; 
			}
		}
		
		void Print(){
			cout<<"�±�\t";
			for(int i = 0 ; i < this->length ; i++){
				printf("%7d ",i);
			}
			cout<<endl<<"Ԫ��\t";
			for(int i = 0 ; i < this->length ; i++){
				if(this->delete_flag[i] == 0){
					printf("%7d ",this->data[i]);	
				}else{
					printf("%7d ",MAX);
				}
			}
			cout<<endl;
		}
}; 

int main()
{
	cout<<"�������ϣ��ı���"<<endl;
	int length,size;
	int* data;
	cin>>length;
	cout<<"���������鳤�ȣ�"<<endl;
	cin>>size; 
	data = new int[size];
	cout<<"���ʼ�����飺"<<endl;
	for(int i = 0 ; i < size ; i++){
		cin>>data[i];
	}
	
	HashTable hashtable(length);
	hashtable.Create_Linear_Probing(data,size);
	cout<<"��ϣ��Ϊ��"<<endl;
	hashtable.Print();
	
	int num;
	cout<<"������ɾ����Ԫ�أ�"<<endl;
	cin>>num;
	cout<<"ɾ��ǰ��ϣ��Ϊ��"<<endl; 
	hashtable.Print();
	if(hashtable.Delete_Linear_Probing(num)){
		cout<<"ɾ�����ϣ��Ϊ��"<<endl;
		hashtable.Print();	
	}else{
		cout<<"��ϣ��û��"<<num<<"���Ԫ��"<<endl; 
	}
	
	cout<<"����������Ԫ�أ�"<<endl;
	cin>>num;
	cout<<"����ǰ��ϣ��Ϊ��"<<endl; 
	hashtable.Print();
	if(hashtable.Insert_Linear_Probing(num)){
		cout<<"������ϣ��Ϊ��"<<endl;
		hashtable.Print();	
	}else{
		cout<<"��ϣ���������޷�����"<<num<<"���Ԫ��"<<endl; 
	}
	
	return 0;
 } 
