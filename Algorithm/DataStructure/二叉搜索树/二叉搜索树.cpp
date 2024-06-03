#include <iostream>
#include <stack>
using namespace std;

int MAX = -32767;

class BinarySearchTree{
	private:
		int data;
		BinarySearchTree* lchild;
		BinarySearchTree* rchild;
	public:
		//������Сֵ
		BinarySearchTree* FindMin(BinarySearchTree* BST){
			BinarySearchTree* cur = BST;
			//������Ϊ��ʱ������NULL 
			if(cur == NULL){
				return NULL;
			} 
			while(cur){
				//������Ϊ��ʱ�����ظýڵ� 
				if(cur->lchild == NULL){
					return cur;
				}else{//������������������Сֵ 
					cur = cur->lchild;
				}
			}
		}
		
		//�������ֵ
		BinarySearchTree* FindMax(BinarySearchTree* BST){ 
			BinarySearchTree* cur = BST;
			//������Ϊ��ʱ������NULL
			if(cur == NULL){
				return NULL;
			} 
			while(cur){
				//������Ϊ��ʱ,���ظýڵ� 
				if(cur->rchild == NULL){
					return cur; 
				}else{//������������������Сֵ 
					cur = cur->rchild;
				}
			}
		}
		
		//��ֵ���ҽ��
		BinarySearchTree* Find(BinarySearchTree* BST,int data){
			BinarySearchTree* cur = BST;
			//������Ϊ�գ�����NULL 
			if(cur == NULL){
				return NULL; 
			}
			while(cur){
				//���ڵ�ֵ��data��ȣ����ظ��ڵ� 
				if(cur->data == data){
					return cur;
				}else if(cur->data < data){
					//��dataС��������������Ѱ�� 
					cur = cur->lchild;
				}else{//��������������Ѱ�� 
					cur = cur->rchild;
				}
			}
		}
		
		//���뺯��
		BinarySearchTree* Insert(BinarySearchTree* BST,int data){
			//������Ϊ�գ��򹹽����ڵ� 
			if(!BST){
				BST = new BinarySearchTree;
				BST->data = data;
				BST->lchild = BST->rchild = NULL; 
			}else{
				//��dataС�ڸ��ڵ��ֵ������뵽������ 
				if(data < BST->data){
					BST->lchild = BST->Insert(BST->lchild,data);
				}else if(data > BST->data){
					//��dataС�ڸ��ڵ��ֵ������뵽������
					BST->rchild = BST->Insert(BST->rchild,data);
				}
			}
			return BST;
		}
		
		//�����������Ĺ���,����data���鹹����������� 
		BinarySearchTree* Create(int* data,int size){
			BinarySearchTree* bst = NULL; 
			for(int i = 0 ; i < size ; i++){
				bst = this->Insert(bst,data[i]);
			}
			return bst;
		}
		
		//�ݹ�ǰ����� 
		void PreorderTraversal(BinarySearchTree* T){
			if(T == NULL){
				return;
			}
			cout<<T->data<<" ";							//���ʸ��ڵ㲢��� 
			T->PreorderTraversal(T->lchild);			//�ݹ�ǰ����������� 
			T->PreorderTraversal(T->rchild);			//�ݹ�ǰ�����������
		}
		
		//�ݹ�������� 
		void InorderTraversal(BinarySearchTree* T){
			if(T == NULL){
				return;
			}
			T->InorderTraversal(T->lchild);				//�ݹ�������������� 
			cout<<T->data<<" ";							//���ʸ��ڵ㲢��� 
			T->InorderTraversal(T->rchild);				//�ݹ�������������� 
		}
		
		//�ݹ������� 
		void PostorderTraversal(BinarySearchTree* T){
			if(T == NULL){
				return;
			}
			T->PostorderTraversal(T->lchild);			//�ݹ������������� 
			T->PostorderTraversal(T->rchild);			//�ݹ������������� 
			cout<<T->data<<" ";							//���ʲ���ӡ���ڵ� 
		}
				
		//ɾ������ 
		BinarySearchTree* Delete(BinarySearchTree* BST,int data){
			if(!BST){//����ʱ��ֱ�ӷ���NULL 
				return BST;
			}else if(data < BST->data){
				//dataС�ڸ��ڵ�ʱ����������ȥɾ��data 
				BST->lchild = this->Delete(BST->lchild,data);
			}else if(data > BST->data){
				//data���ڸ��ڵ�ʱ����������ȥɾ��data 
				BST->rchild = this->Delete(BST->rchild,data); 
			}else{//data���ڸ��ڵ�ʱ 
				if(BST->lchild && BST->rchild){
					//��������������ʱ��������������С��������ڵ�
					BinarySearchTree* tmp = this->FindMin(BST->rchild);
					BST->data = tmp->data;
					//ɾ������������С��� 
					BST->rchild = this->Delete(BST->rchild,tmp->data);
				}else{//������������Ϊ�ջ�����һ����ʱ 
					BinarySearchTree* tmp = BST;
					if(!BST->lchild){//������Ϊ��ʱ 
						BST = BST->rchild;
					}else if(!BST->rchild){//������Ϊ��ʱ 
						BST = BST->lchild; 
					}
					delete tmp; 
				}
			}
			return BST;
		}
		
		int getdata(BinarySearchTree* BST){
			return BST->data;
		}
		
		void FindK(BinarySearchTree* BST , int k){
			stack<BinarySearchTree*> stack;                                   //��ʼ��ջ 
            BinarySearchTree* binary_tree_curr = BST;                           //���浱ǰ��� 
            while(binary_tree_curr || !stack.empty()){
                if(binary_tree_curr->rchild){                           //�Һ��ӷǿ�
                    stack.push(binary_tree_curr);                       //��ǰ�����ջ 
                    binary_tree_curr = binary_tree_curr->rchild;        //���������� 
                }else{
                    //�Һ���Ϊ�գ����ӡ��ǰ������������ 
                    if(binary_tree_curr->data >= k){
                    	cout<<binary_tree_curr->data<<" ";                  	
					} 
                    binary_tree_curr = binary_tree_curr->lchild;
                    //���Ϊ�գ���ջ���գ���ջ���ڵ��ջ��������ýڵ㣬  
                    //ͬʱ������������Ϊ��ǰ�ڵ㣬�����жϣ�ֱ����ǰ�ڵ㲻Ϊ��   
                    while(!binary_tree_curr && !stack.empty()){
                        binary_tree_curr = stack.top();
                        if(binary_tree_curr->data >= k){
                    		cout<<binary_tree_curr->data<<" ";                  	
						} 
                        stack.pop();
                        binary_tree_curr = binary_tree_curr->lchild;
                    }
                }
            }
		}
		
		//ɾ����Сֵ
		BinarySearchTree* DeleteMin(BinarySearchTree* BST){
			BinarySearchTree* cur = BST;	//��ǰ��� 
			BinarySearchTree* parent = BST;	//��ǰ���ĸ��ڵ�
			if(cur == NULL){
				return BST;
			}
			//��ǰ�����������ǿ���һֱѭ�� 
			while(cur->lchild != NULL){
				parent = cur;		//���浱ǰ��㸸�ڵ� 
				cur = cur->lchild;	//�ѵ�ǰ���ָ�������� 
			}
			if(cur == BST){//��ǰ���Ϊ����㣬��ֻ�������� 
				BST = BST->rchild;
			}else{
				if(cur->rchild == NULL){//������Ϊ�գ���ΪҶ�ӽڵ� 
					parent->lchild = NULL; 		//���ڵ��������ÿ�
					delete cur;
				}else{//�������ǿ� 
					parent->lchild = cur->rchild;	//�ѵ�ǰ����������ŵ����ڵ���������� 
					delete cur;
				}
			}
			return BST;
		}
		
		//ɾ�����ֵ
		BinarySearchTree* DeleteMax(BinarySearchTree* BST){
			BinarySearchTree* cur = BST;	//��ǰ��� 
			BinarySearchTree* parent = BST;	//��ǰ���ĸ��ڵ�
			if(cur == NULL){
				return BST;
			}
			//��ǰ����������ǿ���һֱѭ�� 
			while(cur->rchild != NULL){
				parent = cur;		//���浱ǰ��㸸�ڵ� 
				cur = cur->rchild;	//�ѵ�ǰ���ָ�������� 
			}
			if(cur == BST){//��ǰ���Ϊ����㣬��ֻ�������� 
				BST = BST->lchild;
			}else{
				if(cur->lchild == NULL){//������Ϊ�գ���ΪҶ�ӽڵ� 
					parent->rchild = NULL;		//���ڵ��������ÿ� 
					delete cur;
				}else{//�������ǿ� 
					parent->rchild = cur->lchild;	//�ѵ�ǰ����������ŵ����ڵ���������� 
					delete cur;
				}
			}
			return BST;
		}
		
		//�ж��Ƿ�Ϊ���������� 
		bool Judge(BinarySearchTree* root,int& MAX){
			if(root == NULL){//��Ϊ����Ϊ���������� 
				return true;
			}
			bool bst_l,bst_r;
			bst_l = Judge(root->lchild,MAX);//�ж��������Ƿ�Ϊ����������
			if(!bst_l || MAX > root->data){
				return false;
			}
			MAX = root->data;
			bst_r = Judge(root->rchild,MAX);//�ж��������Ƿ�Ϊ����������
			if(!bst_r || MAX < root->data){
				return false;
			}
			return true; 
		} 
};

int main()
{
	int size;
	cout<<"�������������"<<endl; 
	cin>>size;
	int* data;
	data = new int[size];
	cout<<"������ÿ������ֵ��"<<endl;
	for(int i = 0 ; i < size ; i++){
		cin>>data[i];
	}
	BinarySearchTree* bst;
	bst = new BinarySearchTree;
	bst = bst->Create(data,size);
	
	cout<<"ǰ��������ݹ飩��"<<endl;
	bst->PreorderTraversal(bst);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	bst->InorderTraversal(bst);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	bst->PostorderTraversal(bst);
	cout<<endl;
	
	BinarySearchTree* bst_max;
	bst_max = bst->FindMax(bst);
	cout<<"���������������ֵΪ��"<<endl;
	cout<<bst_max->getdata(bst_max);
	cout<<endl;
	cout<<"ɾ�����ֵ��"<<endl;
	bst = bst->DeleteMax(bst);
	cout<<"ǰ��������ݹ飩��"<<endl;
	bst->PreorderTraversal(bst);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	bst->InorderTraversal(bst);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	bst->PostorderTraversal(bst);
	cout<<endl;
	
	cout<<"��������������СֵΪ��"<<endl;
	BinarySearchTree* bst_min; 
	bst_min = bst->FindMin(bst);
	cout<<bst_min->getdata(bst_min);	 
	cout<<endl;
	cout<<"ɾ����Сֵ��"<<endl;
	bst = bst->DeleteMin(bst);
	cout<<"ǰ��������ݹ飩��"<<endl;
	bst->PreorderTraversal(bst);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	bst->InorderTraversal(bst);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	bst->PostorderTraversal(bst);
	cout<<endl;
	
	int num;
	cout<<"������Ҫɾ���Ľ�㣺"<<endl;
	cin>>num;
	bst = bst->Delete(bst,num);
	cout<<"ɾ��֮��"<<endl;
	cout<<"ǰ��������ݹ飩��"<<endl;
	bst->PreorderTraversal(bst);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	bst->InorderTraversal(bst);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	bst->PostorderTraversal(bst);
	cout<<endl;
	
	return 0;
 } 
