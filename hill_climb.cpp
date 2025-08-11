#include <bits/stdc++.h>
using namespace std;

bool hill(unordered_map<char, vector<pair<char, int>>>& graph,
              unordered_map<char, int>& heuristic,
              char current, char goal,
              vector<char>& path) 
{
    path.push_back(current);
    if (current == goal) return true;

    vector<pair<char, int>> neighbors = graph[current];
    sort(neighbors.begin(), neighbors.end(),
        [&](auto& a, auto& b) {
            return heuristic[a.first] < heuristic[b.first];
        });

    for (auto& neighbor : neighbors) {
        if (hill(graph, heuristic, neighbor.first, goal, path))
            return true;
    }

    path.pop_back();
    return false;
}

int main() {
    unordered_map<char, vector<pair<char, int>>> graph;
    graph['S'] = {{'A', 3}, {'B', 5}};
    graph['A'] = {{'D', 3}, {'B', 4}, {'S', 3}};
    graph['B'] = {{'A', 4}, {'C', 4}, {'S', 5}};
    graph['C'] = {{'E', 6}, {'B', 6}};
    graph['D'] = {{'A', 3}, {'G', 5}};
    graph['E'] = {{'C', 6}};
    graph['G'] = {{'D', 5}};

    unordered_map<char, int> heuristic = {
        {'S', 10}, {'A', 7}, {'B', 6}, {'C', 7},
        {'D', 5}, {'E', 6}, {'G', 0}
    };

    vector<char> path;
    if (hill(graph, heuristic, 'S', 'G', path)) {
        for (char node : path) cout << node << " ";
        cout << "\n";
    } else {
        cout << "Goal not reachable\n";
    }
}
