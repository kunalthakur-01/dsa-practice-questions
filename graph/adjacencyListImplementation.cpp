#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;


// adjacency list implementation with map
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


// adjacency list implementation with vector
vector<vector<int>> printGraph(int n, int m, vector<vector<int>> edges){
    vector<int> ans[n];

    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        adj[i].push_back(i);

        for(int j = 0; j < ans[i].size(); j++) {
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}

int main() {
    // int m, n;
    // cout<< "Enter number of nodes:-" << endl;
    // cin >> n;

    // cout<< "Enter number of edges:-" << endl;
    // cin >> m;

    // Graph g;

    // cout<< "Enter the edges:-" << endl;
    // for(int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;

    //     g.addEdge(u, v, 0);
    // }
    // g.printGraph();

    vector<vector<int>> edges = {{0,1}, {1,2}, {2,0}};

    vector<vector<int>> adj = printGraph(3, 3, edges);

    for(int i = 0; i < adj.size(); i++){
        cout << adj[i][0] << " -> ";
        for(int j = 1; j < adj[i].size(); j++) {
            cout << adj[i][j] << ", ";
        }
        cout<< endl;
    }

    return 0;
}