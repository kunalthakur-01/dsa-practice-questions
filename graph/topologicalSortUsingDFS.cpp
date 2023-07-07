#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int , list<int>> &adjList){
    visited[node] = 1;

    for(auto i: adjList[node]){
        if(!visited[i]){
            topoSort(i, visited, s, adjList);
        }
    }

    s.push(node);
}

vector<int> topologicalSort(vector<pair<int,int>>& edges, int N, int M){
	unordered_map<int , list<int>> adjList;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    vector<bool> visited(N);
    stack<int> s;

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            topoSort(i, visited, s, adjList);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
} 
