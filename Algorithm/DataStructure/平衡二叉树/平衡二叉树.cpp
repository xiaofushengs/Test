#include <iostream>
using namespace std;

class AVL{
	private:
		int data;		//���ļ�ֵ 
		int height;		//���ĸ߶� 
		AVL* lchild;	//���� 
		AVL* rchild;	//�Һ��� 
	public:
		//������Сֵ
		AVL* FindMin(AVL* avl){
			AVL* cur = avl;
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
		AVL* FindMax(AVL* avl){ 
			AVL* cur = avl;
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
		
		//���뺯��
		AVL* Insert(AVL* avl,int data){
			//ƽ�������Ϊ�գ��򹹽����ڵ� 
			if(!avl){ 
				avl = new AVL;
				avl->data = data;
				avl->height = 0; 
				avl->lchild = avl->rchild = NULL; 
			}else if(data < avl->data){//��dataС�ڸ��ڵ��ֵ������뵽������ 
				avl->lchild = avl->Insert(avl->lchild,data);
				int rheight = this->getHeight(avl->rchild);		//�������߶�
				int lheight = this->getHeight(avl->lchild);		//�������߶�
				//������뵼��������ʧ�⣬������������������2 
				if(lheight - rheight == 2){
					if(data <avl->lchild->data){
						//����Ľ������ӵļ�ֵС
						//��ôһ���ǲ��뵽���ӵ��������ϣ��ʽ���LL��ת 
						avl = this->SingleLeftRotation(avl);	
					}else{//�����ǲ��뵽���ӵ��������ϣ���Ҫ����LR��ת 
						avl = this->DoubleLeftRightRotation(avl);
					}
				}
			}else if(data > avl->data){//��dataС�ڸ��ڵ��ֵ������뵽������
				avl->rchild = avl->Insert(avl->rchild,data);
				int rheight = this->getHeight(avl->rchild);		//�������߶�
				int lheight = this->getHeight(avl->lchild);		//�������߶�
				//������뵼��������ʧ�⣬������������������2
				if(rheight - lheight == 2){
					if(data > avl->rchild->data){
						//����Ľ����Һ��ӵļ�ֵ�� 
						//��ôһ���ǲ��뵽�Һ��ӵ��������ϣ��ʽ���RR��ת 
						avl = this->SingleRightRotation(avl);	
					}else{//�����ǲ��뵽�Һ��ӵ��������ϣ���Ҫ����RL��ת 
						avl = this->DoubleRightLeftRotation(avl);
					}
				}
			}
			//���½��ĸ߶� 
			avl->height = this->Max(this->getHeight(avl->lchild),this->getHeight(avl->rchild))+1;
			return avl;
		}
		
		//�����������Ĺ���,����data���鹹����������� 
		AVL* Create(int* data,int size){
			AVL* avl = NULL; 
			for(int i = 0 ; i < size ; i++){
				avl = this->Insert(avl,data[i]);
			}
			return avl;
		}
		
		//ɾ������
		AVL* Delete(AVL* avl,int data){
			if(!avl){//����ʱ��ֱ�ӷ���NULL 
				return avl;
			}else if(data < avl->data){
				//dataС�ڸ��ڵ�ʱ����������ȥɾ��data,���п���ʹ����������������2 
				avl->lchild = this->Delete(avl->lchild,data);
				int rheight = this->getHeight(avl->rchild);		//�������߶�
				int lheight = this->getHeight(avl->lchild);		//�������߶�
				if(rheight - lheight == 2){//����������������2ʱ 
					if(data > avl->rchild->data){
						//�����data���������ļ�ֵ�������������������ϣ������RR��ת 
						avl = this->SingleRightRotation(avl); 
					}else{//������data���������ļ�ֵС�������������������ϣ������RL��ת 
						avl = this->DoubleRightLeftRotation(avl); 
					}
				}
			}else if(data > avl->data){
				//data���ڸ��ڵ�ʱ����������ȥɾ��data 
				avl->rchild = this->Delete(avl->rchild,data);
				int rheight = this->getHeight(avl->rchild);		//�������߶�
				int lheight = this->getHeight(avl->lchild);		//�������߶�
				if(lheight - rheight == 2){//����������������2ʱ 
					if(data < avl->lchild->data){
						//�����data���������ļ�ֵС�������������������ϣ������LL��ת 
						avl = this->SingleLeftRotation(avl); 
					}else{//������data���������ļ�ֵ�������������������ϣ������LR��ת 
						avl = this->DoubleLeftRightRotation(avl); 
					}
				}
			}else{//data���ڸ��ڵ�ʱ 
				if(avl->lchild && avl->rchild){
					//��������������ʱ��������������С��������ڵ�
					AVL* tmp = this->FindMin(avl->rchild);
					avl->data = tmp->data;
					//ɾ������������С��� 
					avl->rchild = this->Delete(avl->rchild,tmp->data);
				}else{//������������Ϊ�ջ�����һ����ʱ 
					AVL* tmp = avl;
					if(!avl->lchild){//������Ϊ��ʱ 
						avl = avl->rchild;
					}else if(!avl->rchild){//������Ϊ��ʱ 
						avl = avl->lchild; 
					}
					delete tmp; 
				}
			}
			return avl;
		}
		
		//������������������ 
		//�����������������µ�ʧ�⣬����������������е���
		//����������������㣬֮ǰ�ĸ���������ڸ������Һ���
		//������Ϊƽ�������һ���Ƕ�����������Ե�ʵ��µ� 
		AVL* SingleLeftRotation(AVL* avl){
			//ע�⣺avl������һ�����ӽ��tmp 
  			//��avl��tmp������������avl��tmp�ĸ߶ȣ������µĸ����tmp  
			AVL* tmp = avl->lchild;			 
			avl->lchild = tmp->rchild;
			tmp->rchild = avl;
			avl->height = this->Max(this->getHeight(avl->lchild),this->getHeight(avl->rchild))+1;
			tmp->height = this->Max(this->getHeight(tmp->lchild),this->getHeight(avl))+1;
			return tmp;
		}
		
		//������������������ 
		//�����������������µ�ʧ�⣬����������������е���
		//�������Һ���������㣬֮ǰ�ĸ���������ڸ���������
		//������Ϊƽ�������һ���Ƕ�����������Ե�ʵ��µ� 
		AVL* SingleRightRotation(AVL* avl){
			//ע�⣺avl������һ�����ӽ��tmp 
  			//��avl��tmp���ҵ���������avl��tmp�ĸ߶ȣ������µĸ����tmp  
			AVL* tmp = avl->rchild;			 
			avl->rchild = tmp->lchild;
			tmp->lchild = avl;
			avl->height = this->Max(this->getHeight(avl->lchild),this->getHeight(avl->rchild))+1;
			tmp->height = this->Max(this->getHeight(tmp->rchild),this->getHeight(avl))+1;
			return tmp;
		}
		
		//������ת��LR��ת�������������������뵼�¶Ե�ʧ�� 
		AVL* DoubleLeftRightRotation(AVL* avl){
			//ע�⣺avl������һ�����ӽ��B����B������һ�����ӽ��C
  			//��avl��B��C�����ε����������µĸ����C
  			//���ȶ�avl�����������е�������RR��ת
			avl->lchild = this->SingleRightRotation(avl->lchild);
			//Ȼ���avl���е�������LL��ת
			return this->SingleLeftRotation(avl); 
		}
		
		//������ת��RL��ת�������������������뵼�¶Ե�ʧ�� 
		AVL* DoubleRightLeftRotation(AVL* avl){
			//ע�⣺avl������һ�����ӽ��B����B������һ�����ӽ��C
  			//��avl��B��C�����ε����������µĸ����C
  			//���ȶ�avl�����������е�������LL��ת
			avl->rchild = this->SingleLeftRotation(avl->rchild);
			//Ȼ���avl���е�������RR��ת
			return this->SingleRightRotation(avl); 
		}
		
		//������ĸ߶� 
		int getHeight(AVL* avl){
			if(!avl){
				return 0;
			}
			return avl->height;
		}
		
		//�������������ֵ 
		int Max(int a,int b){
			return (a>b)?a:b;
		}
		
		//�ݹ�ǰ����� 
		void PreorderTraversal(AVL* T){
			if(T == NULL){
				return;
			}
			cout<<T->data<<" ";							//���ʸ��ڵ㲢��� 
			T->PreorderTraversal(T->lchild);			//�ݹ�ǰ����������� 
			T->PreorderTraversal(T->rchild);			//�ݹ�ǰ�����������
		}
		
		//�ݹ�������� 
		void InorderTraversal(AVL* T){
			if(T == NULL){
				return;
			}
			T->InorderTraversal(T->lchild);				//�ݹ�������������� 
			cout<<T->data<<" ";							//���ʸ��ڵ㲢��� 
			T->InorderTraversal(T->rchild);				//�ݹ�������������� 
		}
		
		//�ݹ������� 
		void PostorderTraversal(AVL* T){
			if(T == NULL){
				return;
			}
			T->PostorderTraversal(T->lchild);			//�ݹ������������� 
			T->PostorderTraversal(T->rchild);			//�ݹ������������� 
			cout<<T->data<<" ";							//���ʲ���ӡ���ڵ� 
		}
		
		int getdata(AVL* avl){
			return avl->data;
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
	AVL* avl;
	avl = new AVL;
	avl = avl->Create(data,size);
	
	cout<<"ǰ��������ݹ飩��"<<endl;
	avl->PreorderTraversal(avl);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	avl->InorderTraversal(avl);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	avl->PostorderTraversal(avl);
	cout<<endl;
	
	AVL* avl_max;
	avl_max = avl->FindMax(avl);
	cout<<"���������������ֵΪ��"<<endl;
	cout<<avl_max->getdata(avl_max);
	cout<<endl;
	 
	cout<<"��������������СֵΪ��"<<endl;
	AVL* avl_min; 
	avl_min = avl->FindMin(avl);
	cout<<avl_min->getdata(avl_min);	 
	cout<<endl;
	
	int num;
	cout<<"������Ҫɾ���Ľ�㣺"<<endl;
	cin>>num;
	avl = avl->Delete(avl,num);
	cout<<"ɾ��֮��"<<endl;
	cout<<"ǰ��������ݹ飩��"<<endl;
	avl->PreorderTraversal(avl);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	avl->InorderTraversal(avl);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	avl->PostorderTraversal(avl);
	cout<<endl;
	
	cout<<"������Ҫɾ���Ľ�㣺"<<endl;
	cin>>num;
	avl = avl->Delete(avl,num);
	cout<<"ɾ��֮��"<<endl;
	cout<<"ǰ��������ݹ飩��"<<endl;
	avl->PreorderTraversal(avl);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	avl->InorderTraversal(avl);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	avl->PostorderTraversal(avl);
	cout<<endl;
	
	cout<<"������Ҫɾ���Ľ�㣺"<<endl;
	cin>>num;
	avl = avl->Delete(avl,num);
	cout<<"ɾ��֮��"<<endl;
	cout<<"ǰ��������ݹ飩��"<<endl;
	avl->PreorderTraversal(avl);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	avl->InorderTraversal(avl);
	cout<<endl;
	
	cout<<"����������ݹ飩��"<<endl;
	avl->PostorderTraversal(avl);
	cout<<endl;	
	
	return 0;
 } 
