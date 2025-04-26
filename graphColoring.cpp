#include <iostream>
#include <vector>
using namespace std;
bool nextValue(int v, vector<vector<int>>& graph, vector<int>& color, int m, int V) {
    for (int c = 1; c <= m; c++) {
        bool safe = true;
        for (int i = 0; i < V; i++) {
            if (graph[v][i] == 1 && color[i] == c) {
                safe = false;
                break;
            }
        }
        if (safe) return c;
    }
    return 0; // No safe color found
}
bool mColoring(vector<vector<int>>& graph, vector<int>& color, int V, int m, int v) {
    if (v == V) return true;

    int c = nextValue(v, graph, color, m, V);
    if (c != 0) {
        color[v] = c;
        if (mColoring(graph, color, V, m, v + 1)) return true;
        color[v] = 0; // Backtrack
    }
    return false;
}
int main() {
    int V = 4;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors
    vector<int> color(V, 0);

    if (mColoring(graph, color, V, m, 0)) {
        cout << "Solution exists with " << m << " color" << endl;
    } else {
        cout << "Solution does not exist!" << endl;
    }
    return 0;
}
