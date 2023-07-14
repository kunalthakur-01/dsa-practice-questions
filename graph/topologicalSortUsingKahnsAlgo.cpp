#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
	unordered_map<int , list<int>> adjList;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // find indegree of all the node
    vector<int> inDegree(v);
    for(auto i : adjList){
        for(auto j : i.second){
            inDegree[j]++;
        }
    }

    // push the node in the queue whose indegree is zero
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(inDegree[i] == 0) q.push(i);
    }

    // do BFS
    vector<int> ans;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour : adjList[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0) q.push(neighbour);
        }
    }

    return ans;
} 
