#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class MySort{
	private:
		int MAX;
		int* A;
	public:
		//���캯�� 
		MySort(int N){
			this->MAX = N;
			A = new int[this->MAX];
			this->SetArray();
		}
		
		//�����ʼ������ 
		void SetArray(){
			srand(time(0));
			for ( int i = 0 ; i < MAX ; i++){
				A[i] = rand() % 100 + 1; 
			}
		}
		
		//��ӡ���� 
		void Print(){
			int count = 0;
			for ( int i = 0 ; i < MAX ; i++){
				cout<<A[i]<<" ";
				count++;
				if ( count == 10 ){
					cout<<endl;
				}
			}
		}
		
		//�������� 
		void Swap(int* a , int* b){
			int tmp = *a;
			*a = *b;
			*b = tmp;
		}
		
		//ð������ 
		void Bubble_Sort(){
			int count = 0;
			for ( int i = this->MAX - 1 ; i >= 0 ; i--){
				int flag = 0;
				for ( int j = 0 ; j < i ; j++){
					if ( A[j] > A[j+1]){
						this->Swap(&A[j],&A[j+1]);
						count++;
						flag = 1;
					}
				}
				if ( flag == 0){
					break;
				}
			}	
		}
		
		//�������� 
		void  Insertion_Sort(){
			for ( int i = 1 ; i < this->MAX ; i++){
				int tmp = A[i];
				for ( int j = i ; j > 0 && A[j-1] > tmp ; j-- ){
					A[j] = A[i-1];
				}
				A[i] = tmp;
			}
		}
		
		//ϣ������ 
		void Shell_Sort(){
			int Sedgewick[] = { 929,505,209,109,41,19,5,1,0};
			int tmp;
			int i,j,k;
			for ( i = 0 ; Sedgewick[i] >= MAX ; i++);
			for ( j = Sedgewick[i] ; j > 0 ; j = Sedgewick[++i]){
				tmp = A[j];
				for ( k = 0 ; k >= j && A[i-j] > tmp ; k -= j){
					A[k] = A[k-j];
				} 
				A[k] = tmp; 
			}
		}
		
		//������Сֵ���±꺯�� 
		int ScanForMin(int start,int end){
			int index = start;
			int min = A[start];
			for ( int i = start ; i < end ; i++){
				if ( A[i] < min){
					min = A[i];
					index = i;
				}
			}
			return index;
		}
		
		//ѡ������ 
		void Selection_Sort(){
			int MinPosition;
			int i;
			for ( i = 0 ; i < MAX ; i++){
				MinPosition = this->ScanForMin(i,MAX);
				this->Swap(&A[i],&A[MinPosition]);
			}
		}
		
		//һ�ι鲢���� 
		void Merge(int* TmpA,int Left,int Right,int RightEnd){
			int LeftEnd = Right -1;
			int Tmp = Left ;
			int Num = RightEnd - Left + 1;
			while ( Left <= LeftEnd && Right <= RightEnd){
				if ( A[Left] <= A[Right]){
					TmpA[Tmp++] = A[Left++];
				}else{
					TmpA[Tmp++] = A[Right++];
				}
			}
			while(Left <= LeftEnd){
				TmpA[Tmp++] = A[Left++];
			}
			while(Right <= RightEnd){
				TmpA[Tmp++] = A[Right++];
			}
			for ( int i = 0 ; i < Num; i++,RightEnd--){
				A[RightEnd] = TmpA[RightEnd];
			}
		}
		
		//�ݹ�鲢���� 
		void MergeSort(int* TmpA,int Left,int RightEnd){
			int Center;
			if ( Left < RightEnd){
				Center = ( Left + RightEnd) /2;
				MergeSort(TmpA,Left,Center);
				MergeSort(TmpA,Center+1,RightEnd);
				Merge(TmpA,Left,Center+1,RightEnd);
			}
		}
		
		//�ݹ�鲢���� 
		void Merge_Sort1(){
			int* TmpA;
			TmpA = new int[MAX];
			if ( TmpA != NULL){
				this->MergeSort(TmpA,0,this->MAX-1);
				delete TmpA;
			}else{
				cout<<"�ռ䲻��!"<<endl;
			}
		}
		
		//�ǵݹ�һ�ι鲢
		//lengthΪ��ǰ�������еĳ��� 
		void Merge_pass(int* TmpA ,int length){
			//�����鲢������������ 
			int i , j;
			for ( i = 0 ; i <= this->MAX - 2*length ; i += 2*length){
				this->Merge(TmpA,i,i+length,i+2*length-1);
			} 
			if ( i + length < this->MAX){			//�鲢���ʣ2������ 
				this->Merge(A,i,i+length,this->MAX-1);
			}else{//���ʣ1������ 
				for ( j = i ; j < this->MAX ; j++){
					TmpA[j] = A[j];
				}
			}
		}
		
		//�ǵݹ�鲢���� 
		void Merge_Sort2(){
			int* TmpA;
			TmpA = new int[this->MAX];
			int length = 1;
			if ( TmpA != NULL){
				while ( length < this->MAX){
					this->Merge_pass(TmpA,length);
					length *= 2;
					this->Merge_pass(A,length);
					length *= 2;
				}
				delete TmpA;
			}else{
				cout<<"�ռ䲻��"<<endl; 
			} 
		} 
};

int main()
{
	//��ʼ������ 
	int N;
	cout<<"���������鳤��:";
	cin>>N;
	MySort sort(N);
	
	//ð������
	cout<<"ð������ǰ:"<<endl;
	sort.Print();
	sort.Bubble_Sort();
	cout<<"ð�������:"<<endl;
	sort.Print();
	
	//��������
	cout<<"��������ǰ:"<<endl;
	sort.SetArray();
	sort.Print();
	sort.Insertion_Sort(); 
	cout<<"���������:"<<endl;
	sort.Print();
	
	//ϣ������ 
	cout<<"ϣ������ǰ:"<<endl;
	sort.SetArray();
	sort.Print();
	sort.Shell_Sort(); 
	cout<<"ϣ�������:"<<endl;
	sort.Print();
	
	//ѡ������ 
	cout<<"ѡ������ǰ:"<<endl;
	sort.SetArray();
	sort.Print();
	sort.Selection_Sort(); 
	cout<<"ѡ�������:"<<endl;
	sort.Print();
	
	//�鲢����(�ݹ鷨) 
	cout<<"�鲢����(�ݹ�)ǰ:"<<endl;
	sort.SetArray();
	sort.Print();
	sort.Merge_Sort1();
	cout<<"�鲢����(�ݹ�)��:"<<endl;
	sort.Print();
	
	//�鲢����(�ǵݹ鷨) 
	cout<<"�鲢����(�ǵݹ�)ǰ:"<<endl;
	sort.SetArray();
	sort.Print();
	sort.Merge_Sort2();
	cout<<"�鲢����(�ǵݹ�)��:"<<endl;
	sort.Print();
	
	return 0;
 } 
