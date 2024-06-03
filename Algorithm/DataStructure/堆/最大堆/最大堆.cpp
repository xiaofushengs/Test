#include <iostream>
using namespace std;

//��Ϊ���ѵĵ�0��Ԫ�أ���֮Ϊ�ڱ� 
const int MaxData = 1000000;

class MaxHeap{
	private:
		int* data;			//�洢���ݵ����� 
		int size;			//��ǰ��ģ 
		int capacity;		//�������
	public:
		//���ѵĹ��캯�� 
		MaxHeap(int MaxSize){
			this->data = new int[MaxSize];
			this->size = 0;
			this->capacity = MaxSize;
			this->data[0] = MaxData;
		}
		
		//��data[n]Ϊ�����Ӷѵ���Ϊ����
		void Predown(int n){
			//�����±�Ϊn��Ԫ��
			int x = this->data[n];
			int parent,child;
			//�����һ��Ԫ���������һ�����ֵ 
			for(parent = n ; parent*2 <= this->size ; parent = child){
				//childָ��ǰ�������� 
				child = parent*2;
				//���ӵ��±겻����������������˵�����Һ���
				//�Һ��ӵļ�ֵ������ڵ㣬��ôchildָ���Һ��ӣ�������ָ������ 
				if((child != this->size) && this->data[child] < this->data[child+1]){
					child++;//ѡ�����Һ��������ֵ 
				}
				if(x >= this->data[child]){//�ҵ��˺��ʵ�λ�� 
					break;
				}else{//�Ѻ�������
					this->data[parent] = this->data[child];
				}
			}
			this->data[parent] = x; 
		}
		
		//���ѵĽ������� 
		void Create(int* data ,int n){
			//�����ݵ������� 
			for(int i = 0 ; i < n ; i++){
				this->data[++size] = data[i];
			}
			//�����һ�����ĸ��ڵ㿪ʼ��֮Ϊ�������Ӷѵ���Ϊ���� 
			for(int i = this->size/2 ; i > 0 ; i--){
				this->Predown(i); 
			}
		} 
		
		//�ж������Ƿ�����
		bool IsFull(){
			return this->size == this->capacity;
		} 
		
		bool IsEmpty(){
			return this->size == 0;
		}
		
		//���ѵĲ������ 
		bool Insert(int num){
			//�����������޷����� 
			if(this->IsFull()){
				return false;
			}
			//�������һ��Ԫ�ص�λ��
			int i = ++size; 
			//�����һ��Ԫ�صĸ��ڵ㿪ʼ���й���
			//������ڵ�С��num����ô�Ѹ��ڵ����� 
			//data[0]�����ڱ�Ԫ�أ�����С�����������Ԫ�أ�����ѭ������ 
			for(; this->data[i/2] < num ; i /= 2){
				this->data[i] = this->data[i/2];
			}
			this->data[i] = num;
			return true;
		}
		
		//���ѵ�ɾ�����ֵ����
		int DeleteMax(){
			//�����ǿ�ʱ 
			if(this->IsEmpty()){
				return MaxData;
			} 
			int max = this->data[1];
			this->data[1] = this->data[size];
			//���ѹ�ģ��һ 
			this->size--;
			//Ȼ��ѵ�һ��Ԫ��Ϊ�������е���Ϊ���� 
			this->Predown(1);
			return max; 
		}
		
		//��ӡ����
		void Print(){
			for(int i = 1 ; i <= this->size ; i++){
				cout<<this->data[i]<<" ";
			}
		} 
};

int main()
{
	cout<<"���������ѵ����������"<<endl;
	int capacity;
	cin>>capacity;
	MaxHeap maxheap(capacity); 
	cout<<"�������ʼ�����ѵ�Ԫ�ظ���:"<<endl;
	int size,*data;
	cin>>size;
	data = new int[size];
	cout<<"���ʼ��Ԫ��:"<<endl;
	for(int i = 0 ; i < size ; i++){
		cin>>data[i];
	}
	maxheap.Create(data,size);
	cout<<"����Ϊ:"<<endl;
	maxheap.Print();
	cout<<endl;
	
	//�������в���Ԫ��
	cout<<"������Ҫ�����Ԫ�أ�"<<endl;
	int num;
	cin>>num;
	maxheap.Insert(num);
	cout<<"����Ϊ:"<<endl;
	maxheap.Print(); 
	cout<<endl;
	
	cout<<"����ɾ������"<<endl;
	int x = maxheap.DeleteMax();
	cout<<"ɾ��Ԫ��Ϊ��"<<x<<endl;
	cout<<"����Ϊ:"<<endl;
	maxheap.Print();
	
	return 0;
 } 
