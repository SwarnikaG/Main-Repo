#include <iostream>
using namespace std;

class Graph {
    public : 
        int v;
        bool** adjMatrix;
        Graph(int n){
            v=n;
            adjMatrix = new bool*[n];
            for(int i=0;i<n;i++){
                adjMatrix[i] = new bool[n];
                for (int j = 0; j < n; j++)
                    adjMatrix[i][j] = false;
            }
        }
        void add_edge(int u, int v){
            adjMatrix[u][v] = true;
            adjMatrix[v][u] = true;
        }
        void print(){
            for (int i = 0; i < v; i++) {
            cout << i << " : ";
            for (int j = 0; j < v; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
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
