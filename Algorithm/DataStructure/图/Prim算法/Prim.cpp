#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 65535;

//���� 
class Edge{
	private:
		int Start_Vertex;	//��ʼ��
		int End_Vertex;		//��ֹ��
		int Weight;			//�ߵ�Ȩ��
	public:
		//���캯��
		Edge(int start_vertex,int end_vertex , int weight){
			this->Start_Vertex = start_vertex;
			this->End_Vertex = end_vertex;
			this->Weight = weight;
		}
		
		//��ӡ��
		void Print(){
			cout<<this->Start_Vertex<<"\t"<<this->End_Vertex<<"\t"<<this->Weight<<endl;
		}	 
};

//ͼ�� 
class Graph{
	private:
		int** G;		//�ڽӾ���
		int Nv;			//������
		int* dist;		//�������飬�������㵽��С�������ľ��� 
		int* parent;	//���׽ڵ�����
		vector<Edge>   MST;		//��С�������ı߼��� 
	public:
		//���캯��
		Graph(int nv ,int ne){
			this->Nv = nv;
			this->MST.reserve(ne);
			this->G = new int*[nv+1];
			this->dist = new int[nv+1];
			this->parent = new int[nv+1];
			for(int i = 0 ; i < nv+1 ; i++){
				this->G[i] = new int[nv+1];
				this->dist[i] = MAX;
				for(int j = 0 ; j < nv+1 ; j++){
					this->G[i][j] = MAX;
				}
			}
			cout<<"���������߳���"<<endl;
			for(int i = 0 ; i < ne ; i++){
				int v1,v2,weight;
				cin>>v1>>v2>>weight;
				this->G[v1][v2] = this->G[v2][v1]= weight;
			}
		}
		
		//Ѱ����С���붥�㺯��
		int FindMinDist(){
			int MinDist = MAX;
			int MinV = 0;
			for(int i = 1 ; i < this->Nv+1 ; i++){//��ÿ��������б��� 
				// ��Vδ����¼����dist[V]��С
				if(this->dist[i] != 0 && this->dist[i] < MinDist){
					//������С��������С���� 
					MinDist = this->dist[i];
					MinV = i;
				}
			}
			if(MinDist < MAX){
				//��С����С���������򷵻���Ӧ�Ķ��� 
				return MinV; 
			}
			//���򷵻ػ�-1�Ĵ����־ 
			return -1;
		} 
		
		//����ķ(Prim)�㷨,��vertexΪ���ڵ�ĵ���С������ 
		int Prim(int vertex){
			int cnt = 0;							//��¼����ĸ���
			int sum_weight = 0;					//��С��������Ȩ�غ�
			for(int i = 1 ; i < this->Nv+1 ; i++){
				this->parent[i] = vertex;		//��ʱ�Ѹ��׽���ʼ��Ϊ����ĳ�ʼ���� 
				this->dist[i] = this->G[vertex][i];	//i���㵽��С�������ľ���Ϊvertex��i֮��߳� 
			}
			this->parent[vertex] = -1;	//�ѳ�ʼ�������Ϊ��С�������ĸ��ڵ�
			this->dist[vertex] = 0;		//��¼��ʼ���㣬��ʼ��㵽��С�������ľ���Ϊ0 
			cnt++;	//��¼�Ķ�������1
			while(1){
				int cur_vertex = this->FindMinDist(); 	//Ѱ�ҵ�ǰ��С���붥��
				if(cur_vertex == -1){//δ���ҵ���С�Ľ��
					//�����ֿ��ܣ�һ�����ж����Ѿ�ȫ������¼����С��������
					//�������нڵ㶼����ͨ 
					break; 
				}
				sum_weight += this->dist[cur_vertex];
				//��this->parent[cur_vertex]��cur_vertex���ɱ߲��뵽��С�������ı߼����� 
				Edge edge(this->parent[cur_vertex],cur_vertex,this->dist[cur_vertex]);
				this->MST.push_back(edge);
				cnt++;
				//����˵���Ѿ���¼����С���������ˣ���cur_vertex���㵽��С�������ľ���Ϊ0
				this->dist[cur_vertex] = 0;
				for(int i = 1 ; i < this->Nv+1 ; i++){//�Ե�ǰ��С���붥������е��ڽӵ���б���
					//����ڽӵ�i���Ǹ�����Ҹ�cur_vertexֱ������ 
					if(this->dist[i] != 0 && this->G[cur_vertex][i] < MAX){
						//���cur_vertex��i֮��ı�С��i����С�������İѾ��� 
						if(this->G[cur_vertex][i] < this->dist[i]){
							//������Ӧ���������븸�׽�� 
							this->dist[i] = this->G[cur_vertex][i];
							this->parent[i] = cur_vertex; 
						}
					}
				}
			}                            
			//����ѭ�����������ֿ��ܣ�һ�����ж����Ѿ�ȫ������¼����С��������
			//�������нڵ㶼����ͨ ������Ҫ�ж���С�������Ľ���Ƿ��붥������ͬ 
			if(cnt != this->Nv){
				sum_weight = -1;
			}
			return sum_weight; 
		}
		
		//��ӡ��С�������ı߼��� 
		void Print_Prim(){
			vector<Edge>:: iterator it;
			cout<<"Prim�㷨�������С�������ı߼���Ϊ��"<<endl;
			cout<<"Դ��\t�յ�\tȨ��"<<endl;
			for(it = this->MST.begin() ; it != this->MST.end() ; it++){
				it->Print();
			}
		}
};

int main()
{
	int nv,ne;
	cout<<"�����붥���������:"<<endl;
	cin>>nv>>ne;
	Graph graph(nv,ne);
	cout<<"����һ����ʼ���㣺"<<endl;
	int vertex;
	cin>>vertex;
	int min_weight = graph.Prim(vertex);
	cout<<min_weight;
	if(min_weight != -1){
		cout<<"Prim�㷨���ɵ���С��������Ȩ�غ�Ϊ��"<<endl;
		cout<<min_weight<<endl;
		graph.Print_Prim();	
	}
	
	return 0;
 } 
