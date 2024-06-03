#include <cstdlib>
using namespace std;

//��ʼ������ 
void SetArray(int* data,int size)
{
	//srand(time(0));
	cout<<"�����ʼ��"<<size<<"����"<<endl;
	for(int i = 0 ; i < size ; i++){
		data[i] =rand()%100+1;
	}
}

void Print(int* data ,int size)
{
	for(int i = 0 ; i < size ; i++){
		cout<<data[i]<<" "; 
	}
	cout<<endl;
}

//һ�˹鲢 
void Merge(int* data,int* tmp,int left,int right,int rightend)
{
	int leftend = right-1;
	int size = rightend-left+1;
	int cnt = left;
	while(left <= leftend && right <= rightend){
		if(data[left] < data[right]){
			tmp[cnt++] = data[left++];
		}else{
			tmp[cnt++] = data[right++];
		}
	}
	while(left <= leftend){
		tmp[cnt++] = data[left++];
	}
	while(right <= rightend){
		tmp[cnt++] = data[right++];
	}
	for(int i = 0 ; i < size ; i++,rightend--){
		data[rightend] = tmp[rightend]; 
	}
}

void Msort(int* data,int* tmp,int left,int rightend)
{
	if(left < rightend){
		int mid = (left+rightend)/2;
		Msort(data,tmp,left,mid);
		Msort(data,tmp,mid+1,rightend);
		Merge(data,tmp,left,mid+1,rightend);
	}
}
		
//�鲢����(�ݹ�汾)
void Merge_Sort(int* data,int size)
{
	int* tmp = new int[size];
	if(tmp != NULL){
		Msort(data,tmp,0,size-1);
	}
}
		
void Merge_Pass(int* data,int* tmp,int size,int length)
{
	int i,j;
	//������һ��һ�Թ鲢����ô���鳤��Ҫ�־�����
	//����β�����⴦��ֻ�ȴ������ڶ��� 
	for(i = 0 ; i <= size-2*length ; i+=2*length){
		Merge(data,tmp,i,i+length,i+2*length-1);
	}
	if(i+length < size){
		//����һ����Ҫ�鲢
		Merge(data,tmp,i,i+length,size-1);
	}else{//ֻʣ������������ֱ�ӵ��뵽tmp 
		for(j = i ; j < size ; j++){
			tmp[j] = data[j];
		}
	}
}
		
//�鲢����(�ǵݹ�����)
void Merge_Sort1(int* data,int size)
{
	int* tmp;
	tmp = new int[size];
	int length = 1;
	if(tmp != NULL){
		while(length < size){
			Merge_Pass(data,tmp,size,length);
			length*=2;
			Merge_Pass(tmp,data,size,length);
			length*=2;
		}
		delete tmp;
	}
}

int main()
{
	cout<<"���������鳤��:"<<endl;
	int size,*data;
	cin>>size; 
	data = new int[size];
	
	SetArray(data,size);
	cout<<"�鲢���򣨵ݹ�汾��ǰ��"<<endl;
	Print(data,size);
	cout<<"�鲢���򣨵ݹ�汾����"<<endl;
	Merge_Sort(data,size);
	Print(data,size);
		
	SetArray(data,size);
	cout<<"�鲢���򣨷ǵݹ�汾��ǰ��"<<endl;
	Print(data,size);
	cout<<"�鲢���򣨷ǵݹ�汾����"<<endl;
	Merge_Sort1(data,size);
	Print(data,size);
	
	return 0;
 } 
