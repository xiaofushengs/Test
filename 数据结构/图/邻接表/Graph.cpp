#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph{
    private:
        int V; //������
        vector<list<int>> adjList; //�ڽӱ�

    public:
        Graph(int v){
            this->V=v;
            adjList.resize(V);
        }

        void addEdge(int src,int dest){
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }

        void printGraph() const{
            for(int i=0;i<V;i++){
                cout<<"����"<<i<<"���ڽӱ�";
                for(const auto& kk :adjList[i]){
                    cout<<"->"<<kk;
                }
                cout<<endl;
            }
        }
        

        void DFS(int start)const{
            
        }
};

int main() {
    // ����һ������4�������ͼ
    Graph graph(4);

    // ��ӱ�
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);

    // ��ӡͼ���ڽӱ�
    graph.printGraph();

    return 0;
}