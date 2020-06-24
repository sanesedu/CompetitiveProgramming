
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 1e9

#define MAX_V 200

using namespace std;

int res[MAX_V][MAX_V];

vector<int> p, dist;

int mf, f, s, t, n, m;

void augment(int u, int minEdge) {
    if(u == s) {
        f = minEdge;
        return;
    } else if(p[u] != -1) {
        augment(p[u], min(minEdge, res[p[u]][u]));
        res[p[u]][u] -= f;
        res[u][p[u]] += f;
    }
}

void edmondKarp() {
    
    mf = 0;

    while(1) {
       
        f = 0;
        
        dist.assign(MAX_V, INF);
        p.assign(MAX_V, -1);

        dist[s] = 0;
        
        queue<int> q;
        q.push(s);
    
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(u == t) break;

            for(int i = 0; i < MAX_V; ++i) {
                if(res[u][i] > 0 && dist[i] == INF) {
                    dist[i] = dist[u] + 1;
                    q.push(i);
                    p[i] = u;
                } 
            }
        } 

        augment(t, INF);

        if(f == 0) break;
        else mf += f;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    map<string, int> mp;
    mp["XXL"] = 1;
    mp["XL"] = 2;
    mp["L"] = 3;
    mp["M"] = 4;
    mp["S"] = 5;
    mp["XS"] = 6;

    int q;
    cin >> q;

    string st;

    while(q--) {
        cin >> n >> m;

        memset(res, 0, sizeof(res));

        s = 0;
        t = 7 + m;

        for(int i = 1; i <= 6; ++i) {
            res[s][i] = n / 6;
        }

        for(int i = 7; i < 7 + m; ++i) {
            res[i][t] = 1;
        } 
    
        for(int i = 7; i < 7 + m; ++i) {
            cin >> st;
            res[mp[st]][i] = 1;
            cin >> st;
            res[mp[st]][i] = 1;
        }

        edmondKarp();
    
        if(m == mf) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
