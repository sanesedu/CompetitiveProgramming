
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 1000000000

using namespace std;

int djres;

int djikstra(vector<vector<pair<int, int>>> graph, int a, int b, int v) {

    vector<int> dist(v+1, INF);

    dist[a] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(0, make_pair(0, a)));

    while(!pq.empty()) {
        pair<int, pair<int, int>> front = pq.top();
        pq.pop();

        int d = front.first;
        int s = front.second.first;
        int u = front.second.second;

        if(d > dist[u]) continue;

        if(u == b) {
            djres = s;
            return d;
        }

        vector<pair<int, int>>::iterator it;

        for(it = graph[u].begin(); it != graph[u].end(); ++it) {
            if(dist[u] + it->second < dist[it->first]) {
                dist[it->first] = dist[u] + it->second;
                pq.push(make_pair(dist[it->first], make_pair(s + 1, it->first)));
            }
        }
    }
    
    return -1; 
}

int bfs(vector<vector<pair<int, int>>> graph, int a, int b, int v) {

    bool visited[v];
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    
    visited[a] = true;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        if(p.first == b) return p.second;

        vector<pair<int, int>>::iterator it;

        for(it = graph[p.first].begin(); it != graph[p.first].end(); ++it) {
            if(!visited[it->first]) {
                visited[it->first] = true;
                q.push(make_pair(it->first, p.second + 1));
            }
        }
    }
    
    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int v, e, a, b, w, t;

    while(cin >> v >> e) {
        
        vector<vector<pair<int, int>>> graph(v);

        fori(i, e) {
            cin >> a >> b >> w;
            --a;
            --b;
            graph[a].pb(make_pair(b, w));
            graph[b].pb(make_pair(a, w));
        }
        
        cin >> t;

        while(t--) {
            
            cin >> a >> b;
            --a;
            --b;
            int res = bfs(graph, a, b, v);

            if(res == -1) cout << "SIN CAMINO\n";
            else {
                int dj = djikstra(graph, a, b, v);
                cout << dj << " ";
                if(res == djres) cout << "SI\n";
                else cout << "NO\n";
            }
        }
        cout << "----\n";
    }

    return 0;
}
