#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);
        if(!direction) adj[v].push_back(u);
    }

    void printGraph() {
        for(auto i: adj){
            cout<< i.first << " -> ";
            for(auto j: i.second){
                cout<< j << ", ";
            }
            cout<< endl;
        }
    }
};

int main() {
    int m, n;
    cout<< "Enter number of nodes:-" << endl;
    cin >> n;

    cout<< "Enter number of edges:-" << endl;
    cin >> m;

    Graph g;

    cout<< "Enter the edges:-" << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    g.printGraph();
    return 0;
}