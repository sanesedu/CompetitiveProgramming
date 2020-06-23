
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool visited[110];

void bfs(vector<vector<int>> graph, int s) {

    visited[s] = true;

    queue<int> q;

    q.push(s);

    while(!q.empty()) {
       
        int u = q.front();
        q.pop();

        vector<int>::iterator it;

        for(it = graph[u].begin(); it != graph[u].end(); ++it) {
            if(!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        } 
    }
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
            --a;
            --b;
            graph[a].pb(b); 
            graph[b].pb(a); 
        }
       
        memset(visited, false, sizeof(visited));

        bfs(graph, 0);
        
        bool flag = false;

        for(int i = 0; i < v && !flag; ++i) {
            if(!visited[i]) flag = true;
        }
        
        if(flag) cout << "A PIE\n";
        else cout << "BICI\n";
    }

    return 0;
}
