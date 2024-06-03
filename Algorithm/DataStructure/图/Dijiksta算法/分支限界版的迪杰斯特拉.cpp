#include <iostream>
#include <cstring>
#include <stack>
#include <queue> 
#include <vector> 
#include <stdio.h>
using namespace std;

const int MAX = 65535;
int G[1001][1001];
int dist[1001],path[1001];
int Nv,Ne;
int start; 

struct cmp{
	bool operator()(int a,int b){
		return dist[a]>dist[b];
	}
};


void Create_Graph()
{
	//��ʼ����������Ϊ������ 
	for(int i = 0 ; i < Nv+1 ; i++){
		dist[i] = MAX;
	}
	//��ʼ��·������Ϊ-1 
	memset(path,-1,sizeof(path[0])*(Nv+1));
	//memset(this->collected,0,sizeof(this->collected[0])*(nv+1));
	for(int i = 0 ; i < Nv+1 ; i++){
		for(int j = 0 ; j < Nv+1 ; j++){
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
		G[v1][v2] = weight;
		G[v2][v1] = weight;
	}	
}

//�Ͻ�˹�����㷨 
bool Dijikstra(int vertex)
{
	//��ʼ��Դ�����distΪ0 
	dist[vertex] = 0;
	priority_queue<int,vector<int>,cmp> q;
	//Դ���������С�� 
	q.push(vertex);
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
			// i��start����С�������dist[start]+G[start][i]
			if(dist[i] > dist[start] + G[start][i]){
				dist[i] = dist[start] + G[start][i];
				q.push(i);
				path[i] = start;
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
	cout<<"  "<<"���·������Ϊ��"<<dist[end]<<endl;
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
