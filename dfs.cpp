#include <bits/stdc++.h>
using namespace std;

void dfs(char node, char goal, unordered_map<char, vector<char>> &adj, vector<char> &path, unordered_map<char,bool> &visited){
  path.push_back(node);
  visited[node] = true;

  if (node == goal){
    for (char p : path)
      cout << p << " ";
    return;
  }

  for (char next : adj[node]){
    if(visited[next]!=true)dfs(next, goal, adj, path,visited);
  }

  path.pop_back();
  return;
}

int main()
{
  unordered_map<char, vector<char>> graph;
  graph['S'] = {'A', 'B'};
  graph['A'] = {'D', 'B', 'S'};
  graph['B'] = {'A', 'C', 'S'};
  graph['C'] = {'E', 'B'};
  graph['D'] = {'A', 'G'};
  graph['E'] = {'C'};
  graph['G'] = {'D'};

  vector<char> path;
  unordered_map<char,bool> visited;
  dfs('S', 'G', graph, path, visited);
}
