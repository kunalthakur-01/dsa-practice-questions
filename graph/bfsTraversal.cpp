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

void bfs(unordered_map<int , set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);

        for(auto i : adjList[frontNode]) {
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> printGraph(int vertex, vector<pair<int, int>> edges){
    unordered_map<int , set<int>> adjList;

    vector<int> ans;
    unordered_map<int, bool> visited;

    preparedList(adjList, edges);

    for(int i = 0; i < vertex; i++) {
        if(!visited[i]) bfs(adjList, visited, ans, i);
    }

    return ans;
}

int main() {

    // printGraph();

    return 0;
}