#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void preparedList(unordered_map<int , list<int>> &adjlist, vector<pair<int, int>> edges){
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
    }
}

// using DFS*****************************************************************************************************************************
bool isCycle(int node, unordered_map<int , list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto i : adjList[node]) {
            if(!visited[i]){
                bool cycleDetected = isCycle(i, adjList, visited, dfsVisited);
                if(cycleDetected) return true;
            }
            else if(dfsVisited[i]) {
                return true;
            }
        }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> edges){
    unordered_map<int , list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    preparedList(adjList, edges);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool cycleFound = isCycle(i, adjList, visited, dfsVisited);
            if(cycleFound == 1) return true;
        }
    }

    return false;
}
