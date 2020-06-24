
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

void print(int n, vector<vector<pair<int, int>>> graph) {
    
    fori(i, n) {
        for(int j = 0; j < graph[i].size(); ++j) {
            cout << "(" << graph[i][j].first << ", " << graph[i][j].second << ") - ";
        }
        cout << endl;
    }

    cout << endl;
}

void print_dist(vector<int> dist) {
    for(int i = 0; i < dist.size(); ++i) {
        cout << i << ": " << dist[i] << endl;
    }
    cout << endl;
}

bool bellman_ford(int n, vector<vector<pair<int, int>>> graph) {
    
    vector<int> dist(n, INF);

    dist[0] = 0;

//    print_dist(dist);
    for(int i = 0; i < n-1; ++i) { //relax all edges n-1 times
        for(int u = 0; u < n; ++u) {
            for(int j = 0; j < (int) graph[u].size(); ++j) {
                pair<int, int> v = graph[u][j];
  //              cout << "INDEX " << u << endl;
    //            cout << dist[v.first] << " - " << dist[u] << " - " << v.second << endl;
                if(dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                }
      //          print_dist(dist);
            }   
        }
    }

    for(int u = 0; u < n; ++u) {
        for(int j = 0; j < (int) graph[u].size(); ++j) {
            pair<int, int> v = graph[u][j];
            if(dist[v.first] > dist[u] + v.second) {
                return true;
            }
        //    print_dist(dist);
        }
    }

    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, n, m, a, b, c;
    cin >> q;

    while(q--) {
        cin >> n >> m;

        vector<vector<pair<int, int>>> graph(n);

        fori(i, m) {
            cin >> a >> b >> c;
            graph[a].pb(make_pair(b, c));
//            graph[b].pb(make_pair(a, c));
        }
       
        //print(n, graph);

        bool negCycle = bellman_ford(n, graph);

        if(negCycle) cout << "possible" << endl;
        else cout << "not possible" << endl;

    }

    return 0;
}
