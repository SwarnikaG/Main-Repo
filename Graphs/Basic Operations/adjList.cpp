#include <iostream>
#include<list>
using namespace std;

class Graph {
    public : 
        int v;
        list<int>* adjList;
        Graph(int n){
            v=n;
            adjList = new list<int>[n];
        }
        void add_edge(int u, int v, bool bidir=true){
            adjList[u].push_back(v);
            if(bidir){
                adjList[v].push_back(u);
            }
        }
        void print(){
            for(int i=0;i<v;i++){
                cout<<i<<"--> ";
                for(auto node:adjList[i])
                {
                    cout<<node<<" ";
                }
			    cout<<endl;
                }
        }
};

int main() {
    Graph g(5);
    g.add_edge(0,1);
	g.add_edge(0,4);
	g.add_edge(1,2);
	g.add_edge(1,3);
	g.add_edge(1,4);
	g.add_edge(2,3);
	g.add_edge(3,4);

	g.print();
	return 0;
}
