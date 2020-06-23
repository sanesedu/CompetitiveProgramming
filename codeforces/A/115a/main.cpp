
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int maxDepth(int s, map<int, vector<int>> &graph) {

    int sum = 0;

    for(int i = 0; i < graph[s].size(); ++i) {
        sum = max(sum, maxDepth(graph[s][i], graph)); //dfs to check max length from each node
    }
    return ++sum; //we add this edge to the length
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, t;
    cin >> n;

    map<int, vector<int>> graph;

    vector<int> roots;

    for(int i = 0; i < n; ++i) {
        cin >> t;
        if(t == -1) {
            roots.push_back(i);
            continue; //doesn't have node above
        }

        --t; //indexing from 0
        graph[t].push_back(i);
    }

    int res = 0;

    for(int i = 0; i < roots.size(); ++i) {
        res = max(res, maxDepth(roots[i], graph));
    }

    cout << res << "\n";

    return 0;
}
