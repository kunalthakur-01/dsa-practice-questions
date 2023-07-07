#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void preparedList(unordered_map<int , list<int>> &adjlist, vector<vector<int>> &edges){
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

bool isCycle(unordered_map<int , list<int>> &adjList, unordered_map<int, bool> &visited, int node){
    unordered_map<int, int> parent;

    parent[node] = -1;
    visited[node] = true;

    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        for(auto i : adjList[frontNode]) {
            if(visited[i] == true && i != parent[frontNode]){
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

string cycleDetection(vector<vector<int>>& edges, int n, int m){
    unordered_map<int , list<int>> adjList;
    unordered_map<int, bool> visited;

    preparedList(adjList, edges);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool ans = isCycle(adjList, visited, i);
            if(ans == 1) return "Yes";
        }
    }

    return "No";
}

