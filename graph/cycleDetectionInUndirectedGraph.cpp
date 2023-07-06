#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void preparedList(unordered_map<int , list<int>> &adjlist, vector<pair<int, int>> &edges){
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

bool isCycle(unordered_map<int , list<int>> &adjList, unordered_map<int, bool> &visited, int node){
    unordered_map<int, bool> parent;

    parent[node] = -1;
    visited[node] = true;

    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        for(auto i : adjList[frontNode]) {
            if(visited[i] && i != parent[node]){
                return true;
            }
            else if(!visited[i]){
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }

    return false;
}

string cycleDetection(int v, int e, vector<pair<int, int>> edges){
    unordered_map<int , list<int>> adjList;
    unordered_map<int, bool> visited;

    preparedList(adjList, edges);

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            bool ans = isCycle(adjList, visited, i);
            if(ans) return "yes";
        }
    }

    return "No";
}

int main() {

    // printGraph();

    return 0;
}