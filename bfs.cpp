#include <bits/stdc++.h>
using namespace std;

void bfs(char node, char goal, unordered_map<char, vector<char>> &adj){
  queue<vector<char>> q;
  q.push({node});
  while (!q.empty()){
    auto path = q.front();
    q.pop();
    char node = path.back();
    if (node == goal){
      for (char c : path)
        cout << c << " ";
      cout << "\n";
      break;
    }
    for (char next : adj[node]){
      auto new_path = path;
      new_path.push_back(next);
      q.push(new_path);
    }
  }
}

int main(){
  unordered_map<char, vector<char>> graph;
  graph['S'] = {'A', 'B'};
  graph['A'] = {'D', 'B', 'S'};
  graph['B'] = {'A', 'C', 'S'};
  graph['C'] = {'E', 'B'};
  graph['D'] = {'A', 'G'};
  graph['E'] = {'C'};
  graph['G'] = {'D'};

  bfs('S', 'G', graph);
}
