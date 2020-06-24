
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

vector<int> dist;

void dijkstra(int s, int n, vector<vector<pair<int, int>>> graph) {
    
    dist.assign(n, INF);
    
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, s));

    while(!pq.empty()) {
        
        pair<int, int> front = pq.top();
        pq.pop();

        int d = front.first;
        int u = front.second;

        if(d > dist[u]) continue;

        for(int j = 0; j < (int) graph[u].size(); ++j) {
            pair<int, int> v = graph[u][j];

            if(dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }

    }

}

int main() {

    int q, n, m, s, t, a, b, c;
    cin >> q;

    fori(j, q) {
        cin >> n >> m >> s >> t;

        vector<vector<pair<int, int>>> graph(n);

        fori(i, m) {
            cin >> a >> b >> c;
            graph[a].pb(make_pair(b, c));
            graph[b].pb(make_pair(a, c));
        }

        dist.clear();

        dijkstra(s, n, graph);

        int res = dist[t];

        printf("Case #%d: ", j+1);

        if(res < INF) {
            cout << res << endl;
        } else {
            cout << "unreachable" << endl;
        }

    }

    return 0;
}
