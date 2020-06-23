
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 100000000

using namespace std;

bool bipartite(vector<vector<int>> graph, int u, int v) {
    
    queue<int> q;
    q.push(u);

    vector<int> color(v, INF);
    
    color[u] = 0;

    bool isBipartite = true;

    while(!q.empty() && isBipartite) {
        
        int s = q.front();
        q.pop();

        vector<int>::iterator it;

        for(it = graph[s].begin(); it != graph[s].end(); ++it) {
            int p = *it;

            if(color[p] == INF) { //not yet visited
                color[p] = 1 - color[s]; //alternate color with parent
                q.push(p);
            } else if(color[p] == color[s]) { //coloring conflict
                isBipartite = false;
                break;
            }
        }
    }

    return isBipartite;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int v, e, a, b;

    while(cin >> v >> e) {
        
        vector<vector<int>> graph(v);

        fori(i, e) {
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        if(bipartite(graph, 0, v)) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}
