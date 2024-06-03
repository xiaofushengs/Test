#include <iostream>
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

void Swap(int* a ,int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Median3(int* data ,int left , int right)
{
	//����swap����������c++�����÷��� 
	int mid = (left+right)/2;
	if(data[left]>data[mid]){
		Swap(&data[left],&data[mid]);
	}
	if(data[left]>data[right]){
		Swap(&data[left],&data[right]);
	}
	if(data[mid]>data[right]){
		Swap(&data[mid],&data[right]);
	}
	//���ʱ���Ѿ�����
	//data[left]<=data[mid]<=data[right]
	return data[mid];
}

void QuickSort(int* data ,int left,int right)
{
	if(left >= right){
		return;
	}
	int pivot = Median3(data,left,right);
	int low,high;
	low = left;
	high = right;
	//�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�
	//�������Ӽ����� 
	while(1){
		//�ҵ���ߵ�һ��������Ԫ���� 
        while(data[++low] < pivot );
        //�ҵ��ʱ��һ��С����Ԫ���� 
        while(data[--high] > pivot);
        if(low < high){
        	Swap(&data[low],&data[high]);	
		}else{
			break;	
		}
    }
	QuickSort(data,left,low-1);//�ݹ����������벿�� 
	QuickSort(data,low+1,right);//�ݹ���������Ұ벿�� 
}

int FindKth(int* data,int low,int high,int k)
{
	if( low == high){
		return data[low];
	}
	int pivot = data[low];
	int low_tmp = low,high_tmp = high;
	while(low < high){
		while(low < high && data[high] > pivot){
			high--;
		}
		data[low] = data[high];
		while(low < high && data[low] < pivot){
			low++;
		}
		data[high] = data[low]; 
	}
	data[low] = pivot;
	if(low == k){
		return data[low];
	}else if(low > k){
		return FindKth(data,low_tmp,low-1,k);
	}else{
		return FindKth(data,low+1,high_tmp,k-low);
	}
}

//�������� 
void Quick_Sort(int* data ,int size)
{
	QuickSort(data,0,size-1);
}

int FindMax(int* data ,int n)
{
	int low = 0, high = n-1,k = n/2;
	int low0 = 0,high0 = n-1,s1 = 0,s2 = 0;
	while(1){
		int pivot = data[low];
		while(low < high){
			while(low < high && data[high] > pivot){
				high--;
			}
			data[low] = data[high];
			while(low < high && data[low] < pivot){
				low++;
			}
			data[high] = data[low]; 
		}
		data[low] = pivot;
		if(low == k-1){
			break;
		}else if(low > k-1){
			low = 0;
			high = high0-1;
		}else{
			low = low0+1;
			high = high0;
		}
	}
	for(int i = 0 ; i < k ; i++){
		s1 += data[i];
	}
	for(int i = k ; i < n ; i++){
		s2 += data[i];
	}
	return s2-s1;
}

void Move(int* data,int size)
{
	int low = 0,high = size-1;
	while(low < high){
		while(low < high && data[low] % 2 != 0){
			low++;
		}
		while(low < high && data[high] % 2 == 0){
			high--;
		}
		if(low < high){
			Swap(&data[low],&data[high]);
			low++;
			high--;
		}
	}
}

int main()
{
	cout<<"���������鳤��:"<<endl;
	int size,*data;
	cin>>size; 
	data = new int[size];
	
	SetArray(data,size);
	cout<<"��������ǰ��"<<endl;
	Print(data,size);
	cout<<"���������"<<endl;
	Quick_Sort(data,size);
	Print(data,size);
	
	/*
	SetArray(data,size);
	cout<<"ǰ��"<<endl;
	Print(data,size);
	cout<<"��"<<endl;
	Move(data,size);
	Print(data,size);
	
	cout<<"������һ����:"<<endl;
	int k;
	cin>>k; 
	SetArray(data,size);
	Print(data,size);
	cout<<"�����е�"<<k<<"С����Ϊ��"<<endl;
	cout<<FindKth(data,0,size-1,k-1); 
	
	SetArray(data,size);
	Print(data,size);
	cout<<FindMax(data,size); */
		
	return 0;
 } 
