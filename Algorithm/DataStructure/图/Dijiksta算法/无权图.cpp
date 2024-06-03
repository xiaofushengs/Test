#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

class Graph{
	private:
		int** G;	 			//�ڽӾ��� 
		int* dist;				//��������
		int* path;				//·������ 
		int Nv;					//������
		int Ne;					//���� 
	public:
		//���캯�� 
		Graph(int nv , int ne){
			this->Nv = nv;
			this->Ne = ne;
			this->G = new int*[nv+1];
			this->dist = new int[nv+1];
			this->path = new int[nv+1];
			memset(this->dist,-1,sizeof(this->dist[0])*(nv+1));
			memset(this->path,-1,sizeof(this->path[0])*(nv+1));
			for(int i = 0 ; i < nv+1 ; i++){
				G[i] = new int[nv+1];
				memset(G[i],0,sizeof(G[i][0])*(nv+1));
			}
			cout<<"������ߣ�"<<endl;
			for(int i = 0 ; i < ne ; i++){
				int a,b;
				cin>>a>>b;
				this->G[a][b] = 1;
				this->G[b][a] = 1;
			}
		}
		
		//��Ȩͼ��Dijikstra
		void Unweighted(int vertex){
			queue<int> queue;		//��ʼ������
			queue.push(vertex);		//��ʼ������
			int cur_vertex;			//��ǰ��� 
			this->dist[vertex] = 0;		//��ʼ���ľ���Ϊ0 
			while(!queue.empty()){
				cur_vertex = queue.front();	//��ͷ������ 
				queue.pop();
				//����cur_vertex��ÿ���ڽӵ� 
				for(int i = 1  ; i < this->Nv+1 ; i++){
					if((this->G[cur_vertex][i] == 1)&& (this->dist[i] == -1)){
						this->dist[i] = this->dist[cur_vertex]+1;//��ǰ���ľ�����cur_vertex�ľ����1 
						this->path[i] = cur_vertex;	//�ѵ�ǰ������һ�������Ϊcur_vertex;
						queue.push(i); 
					}
				}
			}
		}
		
		//��ӡ��Ȩͼ�Ͻ�˹����·��
		void Print_Unweighted(int vertex){
			for(int i = 1 ; i < this->Nv+1 ; i++){
				stack<int> stack;
				stack.push(i);
				cout<<vertex<<"��"<<i<<"�����·��Ϊ��";
				int j = i;
				while(this->path[j] != -1){//·���ϵ�Ԫ��һ����ջ 
					j = this->path[j];
					stack.push(j);	
				}
				//��ӡ·�� 
				cout<<stack.top();
				stack.pop(); 
				while(!stack.empty()){
					cout<<" -> "<<stack.top();
					stack.pop();
				}
				cout<<endl;
			}
		}
};

int main() 
{
	cout<<"�����붥�����������"<<endl; 
	int nv ,ne;
	cin>>nv>>ne;
	Graph graph(nv,ne);
	cout<<"������һ����ʼ�㣺"<<endl;
	int vertex;
	cin>>vertex;
	graph.Unweighted(vertex);
	graph.Print_Unweighted(vertex); 
	
	return 0;
}
