#include <iostream>
#include <cstring> 
#include <queue> 
using namespace std;

class Graph{
	private:
		int** G;					//�ڽӾ���
		int* Indegree;				//���
		int Nv;						//������
		vector<int> TopOrder;		//�������� 
	public:
		//���캯��
		Graph(int nv , int ne){
			this->Nv = nv;
			this->G = new int*[nv+1];
			this->Indegree = new int[nv+1];
			memset(this->Indegree,0,sizeof(this->Indegree[0])*(nv+1));
			for(int i = 0 ; i < nv+1 ; i++){
				this->G[i] = new int[nv+1];
				memset(this->G[i],0,sizeof(this->G[0][0])*(nv+1));
			}
			cout<<"������ߣ�"<<endl;
			//��������ͼ 
			for(int i = 0 ; i < ne ; i++){
				//v1����ʼ���㣬v2����ֹ�� 
				int v1,v2;
				cin>>v1>>v2;
				this->G[v1][v2] = 1;
				this->Indegree[v2]++;	 //��ֹ����ȼ�1 
			}
		}
		
		//��������
		bool TopSort(){
			queue<int> queue;
			//���Ϊ0�Ķ����������� 
			for(int i = 1 ; i < this->Nv+1 ; i++){
				if(this->Indegree[i] == 0){
					queue.push(i);
				}	
			}
			while(!queue.empty()){//���в���һֱѭ�� 
				int vertex = queue.front();
				queue.pop();	//�������
				this->TopOrder.push_back(vertex);//������������� 
				for(int i = 1 ; i < this->Nv+1 ; i++){
					if(this->G[vertex][i] != 0){
						//����vertex��صı���ȥ,����Ӧ������ȼ�1
						this->Indegree[i]--;
						//�������Ϊ0����� 
						if(this->Indegree[i] == 0){
							queue.push(i);
						}
					}
				} 
			}
			//�ж����������Ƿ���Nv������ ,��Ϊ����ѭ������
			//Ҳ�п����Ǵ��ڻ��������� 
			if(this->TopOrder.size() != this->Nv){//û��nv������ 
				return false;//˵�������޻�ͼ 
			}else{
				return true;//˵�����������޻�ͼ 
			}
		}
		
		//��ӡ������
		void Print_TopOrder(){
			for(int i = 0 ; i < this->TopOrder.size() ; i++){
				cout<<this->TopOrder[i]<<" ";
			}
		} 
};

int main()
{
	cout<<"�����붨���������:"<<endl;
	int nv,ne;
	cin>>nv>>ne; 
	Graph graph(nv,ne);
	if(graph.TopSort()){
		cout<<"��ͼ������������Ϊ��"<<endl; 
		graph.Print_TopOrder();
	}
	
	return 0;
 } 
