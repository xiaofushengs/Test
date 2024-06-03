#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph{
    private:
        int V; //顶点树
        vector<list<int>> adjList; //邻接表

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
                cout<<"顶点"<<i<<"的邻接表：";
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
    // 创建一个具有4个顶点的图
    Graph graph(4);

    // 添加边
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);

    // 打印图的邻接表
    graph.printGraph();

    return 0;
}