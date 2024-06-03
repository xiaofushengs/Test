#include <iostream>
#include <cstdlib>
#include <ctime>
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

//��ӡ���� 
void Print(int* data ,int size)
{
	for(int i = 0 ; i < size ; i++){
		cout<<data[i]<<" "; 
	}
	cout<<endl;
}

//�������� 
void Swap(int& a ,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
		
//ð������
void Bubble_Sort(int* data ,int size)
{
	for(int i = size-1 ; i >= 0 ; i--){
		bool flag = false;		//���Ƿ񽻻���־ 
		for(int j = 0 ; j < i ; j++){
			if(data[j+1] < data[j]){
				Swap(data[j],data[j+1]);	
				flag = true;//�����˽��� 
			}
		}
		if(flag == false){//ȫ���޽��� 
			break;
		}
	}
}
		
//ֱ�Ӳ�������
void Insertion_Sort(int* data ,int size)
{
	for(int i = 1 ; i < size ; i++){
		int tmp = data[i];
		int j; 
		for(j = i ; j > 0  && data[j-1] > tmp ; j--){
			//ǰһ�������ں�һ���������н��� 
			data[j] = data[j-1];
		}
		//�ҵ�����λ�ã����в��� 
		data[j] = tmp;
	}
}


//�۰��������
void Binary_Insertion_Sort(int* data,int size)
{
	for(int i = 1 ; i < size ; i++){
		int low = 0,high = i-1;//��i֮ǰ�ҵ����λ�� 
		int tmp = data[i],mid,j;
		while(low <= high){//Ѱ�����λ�� 
			mid = (low+high)/2;
			if(data[mid] < tmp){
				//�����м�ֵ�����Ұ벿��Ѱ�� 
				low = mid+1;
			}else{//С���м�ֵ������벿��Ѱ��
				high = mid-1;
			}
		}
		for(j = i ; j > low ; j--){
			data[j] = data[j-1];
		}
		data[j] = tmp;
	}
 } 
		
//ϣ������ 
void Shell_Sort(int* data ,int size)
{
	//����Sedgewick�������� 
	int Sedgewick[] = {929,505,209,109,41,19,5,1,0};
	int si = 0;
	//Ѱ�Һ��ʳ�ʼ����� 
	for(si = 0 ; Sedgewick[si] >= size ; si++);
	//��ʼϣ������ 
	for(int D = Sedgewick[si] ; D > 0 ; D = Sedgewick[++si]){
		//������һ��D����Ĳ������� 
		for(int i = D ; i < size ; i++){
			int j=0;
			int tmp = data[i];
			for(j = i ; j >= D && data[j-D] > tmp ; j-= D){
				data[j] = data[j-D];
			}
			data[j] = tmp;
		}
	}
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

//�鲢����	
void Msort(int* data,int* tmp,int left,int rightend)
{
	if(left < rightend){
		int mid = (left+rightend)/2;
		Msort(data,tmp,left,mid);//�ݹ�鲢������벿�� 
		Msort(data,tmp,mid+1,rightend);//�ݹ�鲢�����Ұ벿�� 
		Merge(data,tmp,left,mid+1,rightend);//�����Ҳ��ֽ�������鲢 
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
		
//һ�˹鲢����
void Merge_Pass(int* data,int* tmp,int size,int length)
{
	int i;
	for(i = 0 ; i <= size-2*length ; i += 2*length){
		Merge(data,tmp,i,i+length,i+2*length-1);
	}
	if(i+length < size){//�鲢������������� 
		Merge(data,tmp,i,i+length,size-1);
	}else{//�鲢���һ�������� 
		for(int j = i ; j < size ; j++){
			tmp[j] = data[j];
		}
	}
}
//�鲢����(�ǵݹ�����)
void Merge_Sort1(int* data,int size)
{
	int* tmp = new int[size];
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
	
	/*SetArray(data,size);
	cout<<"ð������ǰ��"<<endl;
	Print(data,size);
	cout<<"ð�������"<<endl;
	Bubble_Sort(data,size);
	Print(data,size); 
	
	SetArray(data,size); 
	cout<<"ֱ�Ӳ�������ǰ��"<<endl;
	Print(data,size);
	cout<<"ֱ�Ӳ��������"<<endl;
	Insertion_Sort(data,size);
	Print(data,size); 
	
	SetArray(data,size); 
	cout<<"�۰��������ǰ��"<<endl;
	Print(data,size);
	cout<<"�۰���������"<<endl;
	Binary_Insertion_Sort(data,size);
	Print(data,size); 
	
	SetArray(data,size); 
	cout<<"ϣ������ǰ��"<<endl;
	Print(data,size);
	cout<<"ϣ�������"<<endl;
	Shell_Sort(data,size);
	Print(data,size);*/
	
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
