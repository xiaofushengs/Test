#include <iostream>
#include <stack> 
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

class BinaryTree{
	private:
		char data;
		BinaryTree* lchild;
		BinaryTree* rchild;
	public: 
		//�������ĳ�ʼ������ 
		BinaryTree* Create_BinaryTree(){
			BinaryTree* T = new BinaryTree;
			char ch;
			cin>>ch;
			if(ch == '#'){													//��#���ǽ�����־ 
				T = NULL;
			}else{
				T->data = ch;												//�Ե�ǰ����ʼ�� 
				T->lchild = Create_BinaryTree();						  	//�ݹ鹹�������� 
				T->rchild = Create_BinaryTree();							//�ݹ鹹�������� 
			}
			return T;
		}
		
		//�ݹ�ǰ����� 
		void PreorderTraversal(BinaryTree* T){
			if(T == NULL){
				return;
			}
			cout<<T->data<<" ";												//���ʸ��ڵ㲢��� 
			T->PreorderTraversal(T->lchild);								//�ݹ�ǰ����������� 
			T->PreorderTraversal(T->rchild);								//�ݹ�ǰ�����������
		}
		
		//�ǵݹ�ǰ����� 
		void PreorderTraversal2(BinaryTree* T){
			stack<BinaryTree*> stack;										//��ʼ��ջ 
			BinaryTree* binary_tree_curr = T;								//���浱ǰ��� 
			//��ǰ���Ϊ������ѭ�� 
			while(binary_tree_curr || !stack.empty()){
				cout<<binary_tree_curr->data<<" ";							//��ӡ��ǰ��� 
				stack.push(binary_tree_curr);								//��ǰ�����ջ 
				binary_tree_curr = binary_tree_curr->lchild;				//���������� 
				//��ǰ���Ϊ��Ϊ�գ���ǰ����ջ
				//�����Һ�����Ϊ��ǰ��� 
				while(!binary_tree_curr && !stack.empty()){					
					binary_tree_curr = stack.top();
					stack.pop();
					binary_tree_curr = binary_tree_curr->rchild;
				}
			}
		}
		
		//�ݹ�������� 
		void InorderTraversal(BinaryTree* T){
			if(T == NULL){
				return;
			}
			T->InorderTraversal(T->lchild);								//�ݹ�������������� 
			cout<<T->data<<" ";											//���ʸ��ڵ㲢��� 
			T->InorderTraversal(T->rchild);								//�ݹ�������������� 
		}
		
		//�ǵݹ��������
		void InorderTraversal2(BinaryTree* T){
			stack<BinaryTree*> stack;									//��ʼ��ջ 
			BinaryTree* binary_tree_curr = T;							//���浱ǰ��� 
			while(binary_tree_curr || !stack.empty()){
				if(binary_tree_curr->lchild){							//���ӷǿ�
					stack.push(binary_tree_curr);						//��ǰ�����ջ 
					binary_tree_curr = binary_tree_curr->lchild;		//���������� 
				}else{
					//����Ϊ�գ����ӡ��ǰ������������ 
					cout<<binary_tree_curr->data<<" ";					
					binary_tree_curr = binary_tree_curr->rchild;
					//���Ϊ�գ���ջ���գ���ջ���ڵ��ջ��������ýڵ㣬  
            		//ͬʱ�������Һ�����Ϊ��ǰ�ڵ㣬�����жϣ�ֱ����ǰ�ڵ㲻Ϊ��   
					while(!binary_tree_curr && !stack.empty()){
						binary_tree_curr = stack.top();
						cout<<binary_tree_curr->data<<" ";
						stack.pop();
						binary_tree_curr = binary_tree_curr->rchild;
					}
				}
			}
		}
		
		//�ݹ������� 
		void PostorderTraversal(BinaryTree* T){
			if(T == NULL){
				return;
			}
			T->PostorderTraversal(T->lchild);						//�ݹ������������� 
			T->PostorderTraversal(T->rchild);						//�ݹ������������� 
			cout<<T->data<<" ";										//���ʲ���ӡ���ڵ� 
		}
		
		//�ǵݹ�������
		void PostorderTraversal2(BinaryTree* T){
			stack<BinaryTree*> stack;
			BinaryTree* binary_tree_curr = T;					//��ǰ��� 
			BinaryTree* binary_tree_pre = NULL;				   // ��һ����� 
			//�Ƚ����ĸ��ڵ���ջ
			stack.push(binary_tree_curr);
			//ֱ��ջ��ʱ������ѭ��  
			while(!stack.empty()){
				binary_tree_curr = stack.top();				 //��ǰ�ڵ���Ϊջ���ڵ�  
				//�����ǰ�ڵ�û�����Һ��ӣ����������ӻ��к��ӣ����Ѿ������������  
            	//��ֱ������ýڵ㣬�����ջ��������Ϊ��һ�����ʵĽڵ�  
				if((binary_tree_curr->lchild == NULL && binary_tree_curr->rchild == NULL) ||
					(binary_tree_curr != NULL && binary_tree_curr->lchild == binary_tree_pre || 
												binary_tree_curr->rchild == binary_tree_pre)){
					cout<<binary_tree_curr->data<<" ";
					stack.pop();
					binary_tree_pre = binary_tree_curr; 
				}else{
					//��������������������,�����Һ�������������ջ  
					if(binary_tree_curr->rchild != NULL){
						stack.push(binary_tree_curr->rchild);
					}
					if(binary_tree_curr->lchild != NULL){
						stack.push(binary_tree_curr->lchild);
					} 
				}
			}
		}
		
		//��α���
		void LevelOrderTraversal(BinaryTree* T){
			queue<BinaryTree*> queue;
			BinaryTree* cur = T;
			//ͷ������ 
			queue.push(cur);
			//����Ϊ��ʱѭ������ 
			while(!queue.empty()){
				//����ͷԪ�س��� 
				cur = queue.front();
				queue.pop();
				cout<<cur->data<<" ";
				//���Ӳ�Ϊ����� 
				if(cur->lchild != NULL){
					queue.push(cur->lchild);
				}
				//�Һ��Ӳ�Ϊ��ʱ��� 
				if(cur->rchild != NULL){
					queue.push(cur->rchild);
				}
			} 
		}
		
		//�ݹ�������ĸ߶�
		int getBinaryTreeHeight(BinaryTree* T){
			if(T){
				//�ݹ����������߶� 
				int lheight = T->getBinaryTreeHeight(T->lchild);
				//�ݹ����������߶� 
				int rheight = T->getBinaryTreeHeight(T->rchild);
				//���ĸ߶ȵ������������߶ȵĽϴ��߼�1
				int height = (lheight>rheight)?lheight:rheight;
				height++;
				return height;	
			}
			return 0; 
		}
		
		//�ǵݹ���������߶�
		int getBinaryTreeHeight2(BinaryTree* T){
			if(T == NULL){
				return 0;
			}
			vector<BinaryTree*> queue(110000); 
			int front = -1,rear = -1;
			int last = 0,height = 0;
			BinaryTree* cur = T;
			queue[++rear] = cur;
			while(front < rear){
				cur = queue[++front];
				if(cur->lchild){
					queue[++rear] = cur->lchild;
				}
				if(cur->rchild){
					queue[++rear] = cur->rchild;
				}
				if(front == last){
					height++;
					last = rear;
				}
			}
			return height;
		}
		
		//�ж��ǹ�Ϊ��ȫ������
		bool Judge(BinaryTree* T){
			if(T == NULL){
				return true;
			}
			bool flag = true;
			queue<BinaryTree*> queue;
			BinaryTree* cur = T;
			queue.push(cur);
			while(!queue.empty()){
				cur = queue.front();
				queue.pop();
				//��ǰ���Ϊ�棬���Һ������
				//����ѭ���ж϶����ڴ�ֻ���Ƿ��зǿյ���� 
				if(cur){
					queue.push(cur->lchild);
					queue.push(cur->rchild);
				}else{
					while(!queue.empty()){
						cur = queue.front();
						queue.pop();
						if(cur){
							return false;
						}
					}
				}
			}
			return true;
		} 
		
		//�ݹ��ӡx�������Ƚ�� 
		bool FindAncestors(BinaryTree* T,char data){
			if(T == NULL){
				return false;
			}
			BinaryTree* cur = T;
			if(cur->data == data){
				return true;
			}
			if(FindAncestors(cur->lchild ,data) || FindAncestors(cur->rchild,data)){
				cout<<cur->data<<" ";
				return true; 
			}
			return false;
		}
		
		//�ǵݹ��ӡx�������Ƚ�� 
		void FindAncestors2(BinaryTree* T,char data){
			stack<BinaryTree*> stack;
			BinaryTree* cur = T;
			bool flag; 
			
			while(!stack.empty()||cur){
				if(cur){
					stack.push(cur);
					flag = false;		//����������
					cur = cur->lchild; 
				}else{
					cur = stack.top();
					stack.pop();
					if(!flag){
						flag = true;		//�������Һ��� 
						stack.push(cur);
						cur = cur->rchild;
					}else{
						if(cur->data == data){
							break;
						}
					}
				}
			}
			while(!stack.empty()){
				cur = stack.top();
				stack.pop();
				cout<<cur->data<<" "; 
			}
		} 
		
		//��������Ŀ��
		/*int getWidth(BinaryTree* T){
			BinaryTree* queue[100000];
			int index[100000];
			set<int> s;
			BinaryTree* cur = T;
			int front = -1,rear = -1;
			int last = 0,level = 0;
			int cnt = 0;
			queue[++rear] = cur;
			level++;
			while(front < rear){
				cur = queue[++front];
				index[cnt++] = level;
				s.insert(level);
				if(cur->lchild){
					queue[++rear] = cur->lchild;
				}
				if(cur->rchild){
					queue[++rear] = cur->rchild;
				}
				if(front == last){
					level++;
					last = rear;
				}	
			}
			int max = 0,width ,i = 0;
			for(set<int>::iterator it = s.begin() ; it != s.end() ; it++){
				width = 0;
				for(int j = i; j < cnt ; j++){
					if(index[j] == *it){
						width++;
					}else{
						i = j;
						break;
					} 
				}
				if(width > max){
					max = width;
				}
			}
			return max;
		}*/
		
		//��Ҷ�ӽڵ��Ȩ·������֮��
		int WPL(BinaryTree* T){
			BinaryTree* queue[100];			//���������㹻��Ķ���
			BinaryTree* cur = T;			//ָ����ڵ�ָ��
			int front = -1,rear = -1;		//��ͷ���βָ��
			//lastָ��ÿ������һ����㣬level������� 
			int last = 0,level = 0;
			int sum = 0;				//��Ȩ·������֮��		 
			queue[++rear] = cur;		//���ڵ���� 
			level++;
			//���в�Ϊ��һֱ����ѭ��  
			while(front < rear){
				cur = queue[++front];	//��������
				if(cur->lchild == NULL && cur->rchild == NULL){
					int weight = cur->data-'0';
					sum += (level-1)*weight;
				}
				//���ӷǿ����
				if(cur->lchild){			
					queue[++rear] = cur->lchild;
				}
				//�Һ��ӷǿ����
				if(cur->rchild){			
					queue[++rear] = cur->rchild;
				}
				//��ͷָ���Ǹò����һ�����ʱ 
				if(front == last){			
					level++;				//������һ 
					//���һ�����ָ�����Ƶ���һ������һ����� 
					last = rear;			
				}
			}
			return sum;
		}
		
		void set(char ch){
			this->data = ch;
			this->lchild = this->rchild = NULL;
		}
		
		//�������ڵ�ĺ��� 
		BinaryTree* Creat_Node(char ch){
			BinaryTree* root;
			root = new BinaryTree;
			root->set(ch);
			return root;
		}
		
		//���������������������й���������
		BinaryTree* Pre_In_Build(char* pre ,char* in, int size){
			if(!pre || !in || size < 0){
				cout<<"�������"<<endl;
				return NULL;
			}
			int root_index = 0;
			//Ѱ�Ҹ���� 
			for(root_index = 0 ; root_index < size ; root_index++){
				if(in[root_index] == pre[0]){
					break;
				}else{
					continue;
				}
			}
			if(root_index == size){
				cout<<"�����������������в�ƥ�䣡"<<endl;
				return NULL;
			}
			//��������� 
			BinaryTree* root = this->Creat_Node(pre[0]);
			//�ݹ鹹�������� 
			if(root_index > 0){
				root->lchild = this->Pre_In_Build(pre+1,in,root_index); 
			}
			//�ݹ鹹�������� 
			if(size - root_index - 1 > 0){
				root->rchild = this->Pre_In_Build(pre+root_index+1,in+1+root_index,size-root_index-1);
			}
			return root;
		}
		
		bool PrintPath(BinaryTree* tree,char v,vector<char>& path){
			bool flag = false;
			BinaryTree* cur = tree;
			if(cur == NULL){
				return false;
			}
			path.push_back(cur->data);
			if(!flag && v == cur->data){
				for(int i = 0 ; i < path.size() ; i++){
					cout<<path[i]<<" ";
				}
				cout<<endl;
			}
			if(!flag && cur->lchild){
				flag = this->PrintPath(cur->lchild,v,path);
			}
			if(!flag && cur->rchild){
				flag = this->PrintPath(cur->rchild,v,path);
			}
			path.pop_back();
			return flag;
		} 
};

int main()
{
	/*char pre[8] = {'1', '2', '4', '7', '3', '5', '6', '8'};  
    char in[8] = {'4', '7', '2', '1', '5', '3', '8', '6'};  
	BinaryTree* T = NULL;
	T = T->Pre_In_Build(pre,in,8);*/
	
	cout<<"���ʼ��������:"<<endl;
	BinaryTree* T;
	T = T->Create_BinaryTree();
	
	cout<<"ǰ��������ݹ飩��"<<endl;
	T->PreorderTraversal(T);
	cout<<endl;
	cout<<"ǰ��������ǵݹ飩��"<<endl;
	T->PreorderTraversal2(T);
	cout<<endl; 
	
	cout<<"����������ݹ飩��"<<endl;
	T->InorderTraversal(T);
	cout<<endl;
	cout<<"����������ǵݹ飩��"<<endl;
	T->InorderTraversal2(T);
	cout<<endl; 

	cout<<"����������ݹ飩��"<<endl;
	T->PostorderTraversal(T);
	cout<<endl;
	cout<<"����������ǵݹ飩��"<<endl;
	T->PostorderTraversal2(T);
	cout<<endl; 

	cout<<"��α�����"<<endl;
	T->LevelOrderTraversal(T);
	cout<<endl; 
	
	vector<char> path;
	bool flag = T->PrintPath(T,'5',path);
	
	cout<<"�������߶ȣ��ݹ飩Ϊ:" <<endl;
	cout<<T->getBinaryTreeHeight(T)<<endl;
	
	cout<<"�������߶ȣ��ǵݹ飩Ϊ:" <<endl;
	cout<<T->getBinaryTreeHeight2(T)<<endl;
	
	if(T->Judge(T)){
		cout<<"���ǿ���ȫ������"<<endl; 
	}else{
		cout<<"�ⲻ�ǿ���ȫ������"<<endl; 
	}

	char data = '5';
	cout<<"�ݹ��ӡ"<<data<<"�����Ƚ�㣺"<<endl;
	T->FindAncestors(T,data);
	cout<<endl;
	
	cout<<"�ǵݹ��ӡ"<<data<<"�����Ƚ�㣺"<<endl;
	T->FindAncestors2(T,data);
	cout<<endl;
	
/*	cout<<"�������Ŀ��Ϊ��"<<endl;
	int width = T->getWidth(T);
	cout<<width<<endl;*/  

	cout<<"Ҷ�ӽڵ�Ĵ�Ȩ·��֮��Ϊ:"<<endl;
	int wpl = T->WPL(T);
	cout<<wpl<<endl; 

	return 0;
 } 
