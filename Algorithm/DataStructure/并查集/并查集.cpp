#include <iostream>
#include <string.h>
using namespace std;

class UF{
	private:
		int* array;
		//���鼯�е���ͨ�����ĸ���,��ʼ��Ϊ�����С 
		int count;
	public:
		//���캯�� 
		UF(int size){
			this->count = size;
			array = new int[size];
			for(int i = 0 ; i < size ; i++){
				this->array[i] = -1;
			}
		}
		
		//���Ҳ�����·��ѹ��
		int Find(int x){
			if(this->array[x] < 0){
				return x;
			}else{
				//���Ȳ���x�ĸ��ڵ�array[x]��Ȼ��Ѹ��ڵ���array[x],֮���ٷ��ظ� 
				return this->array[x] = Find(this->array[x]);
			}
		}
		
		//������,�����洢����Ԫ�ظ����ĸ���
		//ͨ���Ը����ıȽ� 
		void Uion(int root1, int root2){
			root1 = this->Find(root1);
			root2 = this->Find(root2);
			if(root1 == root2){
				return;
			}else if(this->array[root1] < this->array[root2]){
				//root1������ļ��ϵĸ�������root2�������ϵĸ���
				//��ΪΪ��ŵ���Ԫ�ظ����ĸ��� 
				this->array[root1] += this->array[root2];
				this->array[root2] = root1;
				count--;
			}else{
				this->array[root2] += this->array[root1];
				this->array[root1] = root2;
				count--;
			}
		}
		
		//�ж����������Ƿ�����һ������ 
		bool check(int root1,int root2){
			root1 = this->Find(root1);
			root2 = this->Find(root2);
			return root1 == root2;
		}
		
		//�Ż���ͨ�������� 
		int getCount(){
			return this->count;
		}
};

int main()
{
	int size;
	cin>>size;
	UF uf(size);
	while(1){
		char ch;
		cin>>ch;
		if(ch == 'S'){
			break;
		}else{
			int root1,root2;
			cin>>root1>>root2;
			switch(ch){
				case 'I':
					uf.Uion(root1,root2);
					break;
				case 'C':
					if(uf.check(root1,root2)){
						cout<<"yes"<<endl;
					}else{
						cout<<"no"<<endl;
					}
					break;
			}
		}
	}
	int count = uf.getCount();
	if(count > 1){
		cout<<"There are "<<count<<" components.";
	}else{
		cout<<"The network is connected."; 
	}
	
	return 0;
}
