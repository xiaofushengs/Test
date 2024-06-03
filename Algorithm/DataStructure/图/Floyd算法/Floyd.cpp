#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

const int MAX = 65535;

class Graph{
	private:
		int** G;					// �ڽӾ���
		int** dist;					// �������� 
		int** path;					// ·������ 
		int Nv;						// ������
	public:
		//���캯��
		Graph(int nv, int ne){
			this->Nv = nv;
			G = new int*[nv+1];
			dist = new int*[nv+1];
			path = new int*[nv+1]; 
			for(int i = 0 ; i < nv+1 ; i++){
				G[i] = new int[nv+1];
				dist[i] = new int[nv+1];
				path[i] = new int[nv+1];
				memset(path[i],-1,sizeof(path[0][0])*(nv+1));
				for(int j = 0 ; j < nv+1 ; j++){
					this->G[i][j] = this->dist[i][j] = MAX;
				} 
				this->G[i][i] = this->dist[i][i] = 0; 
			}
			cout<<"���������Ȩ��:"<<endl;
			for(int i = 0 ; i < ne ; i++){
				int v1,v2,weight;
				cin>>v1>>v2>>weight;
				this->G[v1][v2] = this->G[v2][v1] = weight;
				this->dist[v1][v2] = this->dist[v2][v1] = weight;
			}	
		}
		
		//Floyd�㷨(��Դ���·���㷨) 
		bool Floyd(){
			for(int k = 1 ; k < this->Nv+1 ; k++){	//k�����м䶥�� 
				for(int i = 1  ; i < this->Nv+1 ; i++){//i������ʼ���� 
					for(int j = 1 ; j < this->Nv+1 ; j++){//j�����յ� 
						if(this->dist[i][k] + this->dist[k][j] < this->dist[i][j]){
							this->dist[i][j] = this->dist[i][k] + this->dist[k][j];
							if(i == j && this->dist[i][j] < 0){//�����˸�ֵȦ 
								return false;
							}
							this->path[i][j] = k;
						}					
					}
				}
			}
			return true; 
		}
		
		// ���η�Ѱ��start��end���·�����м��� 
		void Find(queue<int> &q ,int start,int end){
			int mid = this->path[start][end];
			if(mid == -1){
				return;
			}
			Find(q,start,mid);
			q.push(mid);
			Find(q,mid,end);
		}

		//��ӡstart���㵽end�����·�� 
		void Print_Path(int start,int end){
			queue<int> queue;
			queue.push(start);
			this->Find(queue,start,end); 
			queue.push(end);
			cout<<queue.front();
			queue.pop();
			while(!queue.empty()){
				cout<<"->"<<queue.front();
				queue.pop();
			}
			cout<<endl;
		}
		
		void Print_Floyd(){
			int i,j,k;
			for(int i = 1 ; i < this->Nv+1 ; i++){
				for(int j = 1 ; j < this->Nv+1 ; j++){
					cout<<this->path[i][j]<<" ";
				}
				cout<<endl;
			} 
			cout<<"	length		path"<<endl; 
			for(i = 1 ; i < this->Nv+1 ; i++){
				for(j = i+1 ; j < this->Nv+1 ; j++){
					cout<<i<<"->"<<j<<"	";
					cout<<this->dist[i][j]<<"		"; 	
					this->Print_Path(i,j);
				}
				cout<<endl;
			}
		}
};

int main()
{
	cout<<"�����붥������߳���:"<<endl;
	int nv,ne;
	cin>>nv>>ne; 
	Graph graph(nv,ne);
	if(graph.Floyd()){
		cout<<"������������·��Ϊ��"<<endl; 
		graph.Print_Floyd();
	}
	
	return 0;
 }  
