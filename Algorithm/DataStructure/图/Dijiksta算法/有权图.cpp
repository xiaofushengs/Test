/*#include <iostream>
#include <cstring>
#include <stack>
#include <stdio.h>
using namespace std;

const int MAX = 65535;

class Graph{
	private:
		int** G;	 			//�ڽӾ��� 
		int* dist;				//��������
		int* path;				//·������
		int* collected;			//��¼���� 
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
			this->collected = new int[nv+1]; 
			for(int i = 0 ; i < this->Nv+1 ; i++){
				this->dist[i] = MAX;
			}
			memset(this->path,-1,sizeof(this->path[0])*(nv+1));
			memset(this->collected,0,sizeof(this->collected[0])*(nv+1));
			for(int i = 0 ; i < nv+1 ; i++){
				this->G[i] = new int[nv+1];
				for(int j = 0 ; j < nv+1 ; j++){
					this->G[i][j] = MAX; 
				}
			}
			cout<<"���������Ȩ�أ�"<<endl;
			for(int i = 0 ; i < ne ; i++){
				int v1,v2,weight;
				cin>>v1>>v2>>weight;
				this->G[v1][v2] = weight;
				this->G[v2][v1] = weight;
			}
		}
		
		//�����ڽӵ�Ѱ����С���붥��
		int FindMinVertex(){
			int MinDist = MAX;	//��ʼ����С����
			int v,MinV = 0;
			for(v = 1 ; v < this->Nv+1 ; v++){
				if(this->collected[v] == 0 && this->dist[v] < MinDist){
					//vû�б���¼��dist[v]��С
					MinDist = dist[v];
					MinV = v; 
				}
			}
			if(MinDist < MAX){//�ҵ���С��dist 
				return MinV;	//���ض�Ӧ������±� 
			}else{
				return -1;	//�������Ķ��㲻�����򷵻�-1 
			} 
		} 
		
		//��Ȩͼ��Dijikstra(������������Ѱ����С·������)
		bool Dijikstra(int vertex){
			//���ݳ�ʼ����ʼ������������·������ 
			for(int i = 0 ; i < this->Nv+1 ; i++){
				//�ڹ��캯����dist�Ѿ�ȫ����ʼ��ΪMAX
				//G���ڱ�ʱΪȨ�أ�û�б�ʱΪMAX 
				this->dist[i] = this->G[vertex][i];
				if(this->dist[i] < MAX){
					this->path[i] = vertex;
				}
			}
			this->dist[vertex] = 0;		//��ʼ���ľ���Ϊ��
			this->collected[vertex] = 1;	//��ʼ�����Ϊ����¼ 
			while(1){
				//V��δ����¼������dist��С�� 
				int V = this->FindMinVertex(); 
				if(V == -1){//δ�ҵ�������V������ѭ�� 
					break;
				} 
				this->collected[V] = 1;//���Ϊ�Ѿ�����¼ 
				//����ͼ��ÿ������ 
				for(int w = 1 ; w < this->Nv+1 ; w++){
					//��w��V���ڽӵ���δ����¼ 
					if(this->collected[w] == 0 && this->G[V][w] < MAX){
						if(this->G[V][w] < 0){//���ڸ���ʱ 
							return false;	//�����㷨 
						}
						//����¼Vʹ��dist[w]��С 
						if(this->dist[V] + this->G[V][w] < this->dist[w]){
							//����dist[w] 
							this->dist[w] = this->dist[V] + this->G[V][w]; 
							this->path[w] = V;//����·�� 
						} 
					} 
				} 
			}
			return true;
		}
		
		//��ӡ�Ͻ�˹����·��
		void Print_Dijikstra(int vertex){
			for(int i = 1 ; i < this->Nv+1 ; i++){
				if(i == vertex){
					continue;
				} 
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
				cout<<endl<<"���·������Ϊ��"<<this->dist[i]<<endl;
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
	if(graph.Dijikstra(vertex)){
		graph.Print_Dijikstra(vertex); 	
	}
	
	return 0;
}*/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue> 
#include <vector> 
using namespace std;

const int MAX = 65535;
int G[1001][1001];
int dist[1001] = {0};
int path[1001] = {0};
int visited[1001] = {0};
int Nv,Ne;
int start;

struct cmp{
	bool operator()(int &a,int &b){
		return dist[a]>dist[b];
	}
};

void Create_Graph()
{
	//��ʼ����������Ϊ������ 
	for(int i = 0 ; i < 1001 ; i++){
		dist[i] = MAX;
	}
	//��ʼ��·������Ϊ-1 
	memset(path,-1,sizeof(path[0])*(1001));
	//��ʼ����������Ϊ-1 
	memset(visited,0,sizeof(visited[0])*(1001));
	//memset(this->collected,0,sizeof(this->collected[0])*(nv+1));
	for(int i = 0 ; i < 1001 ; i++){
		for(int j = 0 ; j < 1001 ; j++){
			G[i][j] = MAX;	
		}
	}
	//��ʼ��ͼ
	cout<<"�����붥�����������"<<endl; 
	cin>>Nv>>Ne;
	cout<<"���������Ȩ�أ�"<<endl;
	for(int i = 0 ; i < Ne ; i++){
		int v1,v2,weight;
		cin>>v1>>v2>>weight;
		G[v1][v2] = G[v2][v1] = weight;
	}	
}

//�Ͻ�˹�����㷨 
bool Dijikstra(int vertex)
{
	priority_queue<int,vector<int>,cmp> q;
	//Դ���������С�� 
	q.push(vertex);
	//��ʼ��Դ�����distΪ0 
	dist[vertex] = 0;
	visited[vertex] = 1; 
	//��С�Ѳ�Ϊ�գ�һֱѭ�� 
	while(!q.empty()){
		//����С���е�����СԪ�� 
		int start = q.top();
		q.pop();
		for(int i = 1 ; i < Nv+1 ; i++){
			//��ֵȦ���� 
			if(G[start][i] < 0){
				return false;
			}
			// bfs������ӽ�� 
			if (G[start][i] < MAX){
				if(visited[i] == 0){
					// i��start����С�������dist[start]+G[start][i]
					if(dist[i] > dist[start] + G[start][i]){
						dist[i] = dist[start] + G[start][i];
						q.push(i);
						path[i] = start;
					}	
				}	
			}
		}
	}
	return true;
}

//��ӡstart��end�����·�� 
void Print(int start ,int end)
{
	stack<int> stack;
	stack.push(end);
	cout<<start<<"��"<<end<<"�����·��Ϊ��";
	int j = end;
	while(path[j] != -1){//·���ϵ�Ԫ��һ����ջ 
		j = path[j];
		stack.push(j);	
	}
	//��ӡ·�� 
	cout<<stack.top();
	stack.pop(); 
	while(!stack.empty()){
	cout<<" -> "<<stack.top();
	stack.pop();
	}
	cout<<"\n"<<"���·������Ϊ��"<<dist[end]<<endl;
}

void Print_Dijikstra(int vertex)
{
	for(int i = 1 ; i < Nv+1 ; i++){
		if(i == vertex){
			continue;
		} 
		Print(vertex,i); 
	}
}


int main() 
{
	Create_Graph();
	cout<<"������һ����ʼ�㣺"<<endl;
	int vertex;
	cin>>vertex;
	if(Dijikstra(vertex)){
		Print_Dijikstra(vertex); 	
	}
	
	return 0;
}
