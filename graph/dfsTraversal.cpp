#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

void preparedList( unordered_map<int , set<int>> &adjlist, vector<pair<int, int>> &edges){
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}

void dfs(unordered_map<int , set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &compoennt, int node) {
    compoennt.push_back(node);
    visited[node] = 1;

    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(adjList, visited, compoennt, i);
        }
    }
}

vector<vector<int>> DFS(int v, int e, vector<pair<int, int>> edges){
    unordered_map<int , set<int>> adjList;

    preparedList(adjList, edges);

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;


    for(int i = 0; i < v; i++) {
        if(!visited[i]){
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}

int main() {

    // printGraph();

    return 0;
}