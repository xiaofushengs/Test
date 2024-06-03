#include <iostream>
#include <cstring>
#include <vector> 
using namespace std;

const int MAX = 65535; 
const int Min_Data = -32768;

//���鼯 
class UF{
	private:
		int* path;		//���׽�� 
		int size;		//���� 
	public:
		//���캯�� 
		UF(int size){
			this->size = size;
			this->path = new int[size+1];
			memset(this->path , -1 ,sizeof(path[0])*(size+1));
		}
		
		//���Ҳ���,����·��ѹ�� 
		int Find(int x){
			if(this->path[x] < 0){
				return x;
			}else{
				//���Ȳ���x�ĸ��ڵ�path[x]��Ȼ��Ѹ��ڵ���path[x],֮���ٷ��ظ� 
				return this->path[x] = this->Find(this->path[x]);
			}
		}
		
		//������
		void Union(int root1 ,int root2){
			root1 = this->Find(root1);
			root2 = this->Find(root2);
			//���������Ǽ��ϸ������෴��,�󼯺ϲ�С���� 
			if(this->path[root1] < this->path[root2]){//����1�ȼ���2�� 
				this->path[root1] += this->path[root2];
				this->path[root2] = root1;
			}else{//��֮����2�ȼ���1�� 
				this->path[root2] += this->path[root1];
				this->path[root1] = root2;
			} 
		} 
		
		//����Ƿ������·
		bool CheckCircle(int root1, int root2){
			root1 = this->Find(root1);
			root2 = this->Find(root2);
			if(root1 == root2){//���������· 
				return false;
			}else{//��������·
				this->Union(root1,root2);
				return true;
			}
		} 
};

//���� 
class Edge{
	private:
		int Start_Vertex;	//��ʼ��
		int End_Vertex;		//��ֹ��
		int Weight;			//�ߵ�Ȩ��
	public:
		//���캯��
		void Set(int start_vertex,int end_vertex ,int weight){
			this->Start_Vertex = start_vertex;
			this->End_Vertex = end_vertex;
			this->Weight = weight;
		}
		
		//��ӡ��
		void Print(){
			cout<<this->Start_Vertex<<"\t"<<this->End_Vertex<<"\t"<<this->Weight<<endl;
		}
		
		int getWeight(){
			return this->Weight;
		}
		
		int getStartVertex(){
			return this->Start_Vertex;
		}
		
		int getEndVertex(){
			return this->End_Vertex;
		}
};

class MinHeap{
	private:
		vector<Edge> Edges;		//�߼�����
		int capacity;		//������� 
		int size;			//��ǰ��ģ 
	public:
		//���캯��
		MinHeap(int size){
			this->capacity = size*2; 
			this->size = 0;
			this->Edges.reserve(this->capacity);
			Edge edge;
			edge.Set(0,0,Min_Data);
			this->Edges.push_back(edge);
		}
		
		//��Edge[n]Ϊ�����Ӷѵ���Ϊ��С�� 
		void PreDown(int n){
			Edge edge = this->Edges[n];	//�����±�Ϊn�ı�
			int parent,child;
			for(parent = n ; parent*2 <= this->size ; parent = child){
				child = parent*2;
				if(child != this->size){
					int wl = this->Edges[child].getWeight();//����Ȩ�� 
					int wr = this->Edges[child+1].getWeight();//�Һ���Ȩ��
					if(wr < wl){//�Һ���Ȩ��С������Ȩ�� 
						child++;//ѡ���Һ��� 
					}
				}
				//������ڵ�Ȩ��С���Ӷѣ���ô�ҵ�����λ�ã�����ѭ�� 
				if(edge.getWeight() < this->Edges[child].getWeight()){
					break;
				}else{
					this->Edges[parent] = this->Edges[child];
				} 
			}
			this->Edges[parent] = edge;
		} 
		
		//������С��
		void Create(vector<Edge> &set){
			for(int i = 0 ; i < set.size() ; i++){
				this->Edges[++this->size] = set[i];
			}
			//�����һ��Ԫ�صĸ��׿�ʼ�����Լ�Ϊ�����Ӷѵ���Ϊ��С�� 
			for(int i = this->size/2 ; i >= 1 ; i--){
				this->PreDown(i);
			}
		}
		
		//ɾ������ 
		Edge DeleteMin(){
			if(this->IsEmpty()){
				Edge edge;
				edge.Set(0,0,Min_Data);
				return edge;
			} 
			Edge min_edge = this->Edges[1];
			this->Edges[1] = this->Edges[this->size];
			this->size--;
			this->PreDown(1);
			return min_edge;
		}
		
		//�ж���С���Ƿ�Ϊ�� 
		bool IsEmpty(){
			return this->size == 0;
		}
		
		void Print(){
			cout<<"��С�ѵ�Ԫ���У�"<<this->size<<endl;
            for(int i = 1 ; i <= this->size ; i++){
                cout<<this->Edges[i].getStartVertex()<<" "<<this->Edges[i].getEndVertex()<<" "<<this->Edges[i].getWeight()<<endl;
            }
        }
};

class Graph{
	private:
		int** G;				//�ڽӾ���
		int Nv;					//������
		int Ne;					//���� 
		vector<Edge> MST;				//��С�������ı߼��� 
		vector<Edge> Edge_Set;			//�߼��� 
	public:
		//���캯��
		Graph(int nv ,int ne){
			this->Nv = nv;
			this->Ne = ne;
			this->MST.reserve(this->Nv-1);
			this->Edge_Set.reserve(ne);
			this->G = new int*[nv+1];
			for(int i = 0 ; i < nv+1 ; i++){
				this->G[i] = new int[nv+1];
				for(int j = 0 ; j < nv+1 ; j++){
					this->G[i][j] = MAX;
				}
			}
			cout<<"���������߳���"<<endl;
			for(int i = 0 ; i < ne ; i++){
				int v1,v2,weight;
				cin>>v1>>v2>>weight;
				this->G[v1][v2] = this->G[v2][v1]= weight;
				Edge edge;
				edge.Set(v1,v2,weight);
				Edge_Set.push_back(edge); 
			}
		}
		
		//Kruskal�㷨
		int Kruskal(){ 
			int sum_weight = 0;
			UF uf(this->Nv);			//���첢�鼯
			int cnt = 0;
			//����߼�����С�� 
			MinHeap minheap(this->Ne);
			minheap.Create(this->Edge_Set);
			int edge_cnt = 0;
			//��С��������δ��¼Nv-1�����ұ߼����ﻹ�б���һֱѭ�� 
			while(edge_cnt != this->Nv-1 && !minheap.IsEmpty()){
				Edge min_edge = minheap.DeleteMin(); 
				int start= min_edge.getStartVertex();
				int end = min_edge.getEndVertex();
				if(uf.CheckCircle(start,end)){//�����ɻ�·
					//��Ӧ�ı���¼����С������ 
					this->MST.push_back(min_edge);
					this->MST[edge_cnt++] = min_edge;
 					sum_weight += min_edge.getWeight();
				}
			}
			if(edge_cnt < this->Nv-1){
				sum_weight = -1;
			}
			return sum_weight; 
		}
		
		void Print_Kruskal(){
			cout<<"Kruskal�㷨�������С�������ı߼���Ϊ��"<<endl;
			cout<<"Դ��\t�յ�\tȨ��"<<endl;
			for(int i = 0 ; i < this->Nv-1 ; i++){
				Edge edge = this->MST[i];
				edge.Print();
			}	
		}
};

int main()
{
	int nv,ne;
	cout<<"�����붥���������:"<<endl;
	cin>>nv>>ne;
	Graph graph(nv,ne);
	int min_weight = graph.Kruskal();
	if(min_weight != -1){
		cout<<"Kruskal�㷨���ɵ���С��������Ȩ�غ�Ϊ��"<<endl;
		cout<<min_weight<<endl;
		graph.Print_Kruskal();	
	} 
	
	return 0;
 } 
