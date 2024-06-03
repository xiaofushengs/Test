#include <iostream>
#include <queue> 
#include <stack>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

char Arr[10000];

class HuffmanTree{
	private:
		int weight;
		string Huffmancode;
		HuffmanTree* lchild;
		HuffmanTree* rchild;
	public:		
		void Set(int num,HuffmanTree* left ,HuffmanTree* right){
			this->weight = num;
			this->lchild = left;
			this->rchild = right;
		}
		
		int getWeight(){
			return this->weight;
		}
		
		bool isLeaf(HuffmanTree* root){
			return !root->lchild && !root->rchild;
		}
		
		//��������������
		void Create_HuffmanCode(HuffmanTree* root,char* Arr,int top){
			if(root->lchild){
				Arr[top] = '0';
				Create_HuffmanCode(root->lchild,Arr,top+1);
			}
			if(root->rchild){
				Arr[top] = '1';
				Create_HuffmanCode(root->rchild,Arr,top+1);
			}
			if(this->isLeaf(root)){
				int i;
				for(int i = 0 ; i < top ; i++){
					if(Arr[i-1] == ' ' &&Arr[i] != ' '){
						break;
					}
				}
				string code(Arr,top);
				int index;
				while( (index = code.find(' ')) != code.npos){
					code = code.erase(index,1);
				}
				root->Huffmancode = code;
			}
		} 
		
		void PrintHuffmanTree(HuffmanTree* root){
			queue<HuffmanTree*> q;
			q.push(root);
			while(!q.empty()){
				HuffmanTree* cur = q.front();
				q.pop();
				if(cur->lchild){
					q.push(cur->lchild);
				}
				if(cur->rchild){
					q.push(cur->rchild);
				}
				if(this->isLeaf(cur)){
					cout<<cur->weight<<"�Ĺ���������Ϊ��"<<cur->Huffmancode<<endl;
				}
			}
		}
		
		//�ݹ�ǰ����� 
		void PreorderTraversal(HuffmanTree* T){
			if(T == NULL){
				return;
			}
			cout<<T->weight<<" ";												//���ʸ��ڵ㲢��� 
			T->PreorderTraversal(T->lchild);								//�ݹ�ǰ����������� 
			T->PreorderTraversal(T->rchild);								//�ݹ�ǰ�����������
		}
		
		//�ݹ�������� 
		void InorderTraversal(HuffmanTree* T){
			if(T == NULL){
				return;
			}
			T->InorderTraversal(T->lchild);								//�ݹ�������������� 
			cout<<T->weight<<" ";											//���ʸ��ڵ㲢��� 
			T->InorderTraversal(T->rchild);								//�ݹ�������������� 
		}
		
		//�ݹ������� 
		void PostorderTraversal(HuffmanTree* T){
			if(T == NULL){
				return;
			}
			T->PostorderTraversal(T->lchild);						//�ݹ������������� 
			T->PostorderTraversal(T->rchild);						//�ݹ������������� 
			cout<<T->weight<<" ";									//���ʲ���ӡ���ڵ� 
		}
};

struct cmp{
	bool operator() (HuffmanTree* node1, HuffmanTree* node2){
		return node1->getWeight()>node2->getWeight();
	}
};

HuffmanTree* Create_HuffmanTree(int* data,int size){
	priority_queue<HuffmanTree*,vector<HuffmanTree*>,cmp> Q;
	for(int i = 0 ; i < size ; i++){
		HuffmanTree* root = new HuffmanTree;
		root->Set(data[i],NULL,NULL);
		Q.push(root);
	}
	while(Q.size() != 1){
		HuffmanTree* left = Q.top();
		Q.pop();
		HuffmanTree* right = Q.top();
		Q.pop();
		HuffmanTree* root = new HuffmanTree;
		root->Set(left->getWeight()+right->getWeight(),left,right);
		Q.push(root);
	}
	HuffmanTree* root = Q.top();
	Q.pop();
	return root;
}

int main()
{
	int N,*data;
	cout<<"���������������ʼ�������"<<endl;
	cin>>N;
	data = new int[N];
	for(int i = 0 ; i < N ; i++){
		cin>>data[i];
	}
	
	HuffmanTree *root;
	root = Create_HuffmanTree(data,N);
	root->Create_HuffmanCode(root,Arr,N);
	root->PrintHuffmanTree(root);
	
	cout<<"ǰ��������ݹ飩��"<<endl;
	root->PreorderTraversal(root);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	root->InorderTraversal(root);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	root->PostorderTraversal(root);
	cout<<endl;
	
	return 0;
}
