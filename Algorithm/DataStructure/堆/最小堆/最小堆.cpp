#include <iostream>
using namespace std;

const int MinData = -10000;

class MinHeap{
	private:
		int* data;
		int size;
		int capacity;
	public:
		//��С�ѵĹ��캯�� 
		MinHeap(int maxsize){
			this->data = new int[maxsize];
			this->capacity = maxsize;
			this->size = 0;
			this->data[0] = MinData;
		}
		
		int getSize(){
			return this->size;
		}
		
		//�ж���С���Ƿ�����
		bool IsFull(){
			return this->size == this->capacity;
		} 
		
		//�ж���С���Ƿ�Ϊ��
		bool IsEmpty(){
			return this->size == 0;
		} 
		
		//��С�ѵĲ��뺯��
		bool Insert(int num){
			if(this->IsFull()){//��С������ 
				return false;	
			}
			//���Ȱ�Ԫ�ز��뵽��С�ѵ������
			//�������һ��Ԫ�ص�λ��
			//data[0]�����ڱ�Ԫ�أ�����С�����������Ԫ�أ�����ѭ������ 
			int i = ++this->size;
			for(; this->data[i/2] > num ; i = i/2){
				this->data[i] = this->data[i/2];
			}
			this->data[i] = num;
			return true;
		}
		
		void Create(int* num,int n){
			for(int i = 0 ; i < n ; i++){				
				this->data[++this->size] = num[i];
			}
			for(int i = this->size/2 ; i >= 1 ; i--){
				this->Predown(i);
			}
		}
		
		int DeleteMin(){
			if(this->IsEmpty()){//��С���ѿ� 
				return MinData;
			}
			int min = this->data[0];
			this->size--;
			this->Predown(this->size+1);
			return min;
		} 
		
		//���˺�������data[n]Ϊ�����Ӷѵ���Ϊ��С�� 
		void Predown(int n){
			//�����±�Ϊn��Ԫ��
			int x = this->data[n];
			int parent,child;
			//�����һ��Ԫ���������һ����Сֵ 
			for(parent = n ; parent*2 <= this->size ; parent = child){
				//childָ��ǰ�������� 
				child = 2*parent;
				//���ӵ��±겻������С����������˵�����Һ���
				//�Һ��ӵļ�ֵ������ڵ㣬��ôchildָ���Һ��ӣ�������ָ������ 
				if((child != this->size )&& this->data[child] > this->data[child+1]){
					child++;//ѡ�����Һ�������Сֵ 
				}
				if(x <= this->data[child]){//�ҵ����ʵ�λ��
					break;
				}else{//����Ѻ������� 
					this->data[parent] = this->data[child];
				}
			}
			this->data[parent] = x;
		}
		
		//��ӡ��С��
		void Print(){
			for(int i = 1 ; i <= this->size ; i++){
				cout<<this->data[i]<<" ";
			}
		} 
};

int main()
{
	cout<<"��������С�ѵ����������"<<endl;
	int capacity;
	cin>>capacity;
	MinHeap minheap(capacity);
	cout<<"�������ʼ����С�ѵ�Ԫ�ظ���:"<<endl;
	int size,*num;
	cin>>size;
	num = new int[size];
	cout<<"���ʼ��Ԫ��:"<<endl;
	for(int i = 0 ; i < size ; i++){
		cin>>num[i]; 
	} 
	minheap.Create(num,size);
	cout<<"��С��Ϊ:"<<endl;
	minheap.Print();
	cout<<endl;
	
	return 0;
 } 
