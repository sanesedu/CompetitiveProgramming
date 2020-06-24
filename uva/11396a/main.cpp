
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int color[310];

bool bipartite(vector<vector<int>> graph, int s) {

    color[s] = 0;

    queue<int> q;

    q.push(s);

    while(!q.empty()) {
        
        int p = q.front();
        q.pop();

        vector<int>::iterator it;

        for(it = graph[p].begin(); it != graph[p].end(); ++it) {
            
            if(color[*it] == -1) {
                color[*it] = 1 - color[p];
                q.push(*it);
            } else if(color[*it] == color[p]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int v, a, b;

    while(cin >> v) {
        
        if(v == 0) break;

        vector<vector<int>> graph(v);

        while(cin >> a >> b) {
            if(a == 0 && b == 0) break;
            --a;
            --b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        memset(color, -1, sizeof(color));

        bool res = bipartite(graph, 0);

        if(res) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
