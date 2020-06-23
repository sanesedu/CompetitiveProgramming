
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

struct Stop {
    int line, wait;
    Stop(int l, int w) {
        line = l;
        wait = w;
    }
};

vector<vector<Stop>> stops;

long long adj[110][110];

int mod(int a, int b) {
    if(a - b >= 0) return a - b;
    else return a - b + 60;
}

int n, m, source, waitTime, nxt, elapsed, nl;

long long floydWarshall() {
    
    for(int k = 0; k < m; ++k) {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    long long res = INT_MAX;

    //we get the minimum from choosing any of the lines connected to the initial node
    //being able to get to the end node using any of the lines it is connected to
    for(auto ini: stops[1]) {
        for(auto end: stops[n]) {
            res = min(res, adj[ini.line][end.line]);
        }
    }
    
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string s;
    stringstream ss;

    while(cin >> n >> m) {
        vector<Stop> vi;
        stops.assign(n + 2, vi);
        
        fori(i, m) {
            cin >> source;
            
            stops[source].pb(Stop(i, 0));
            
            getline(cin, s);
            ss.clear();
            ss.str(s);
            
            elapsed = 0;
            
            while(ss >> waitTime >> nxt) {
                elapsed += waitTime;
                stops[nxt].pb(Stop(i, elapsed));
            }
        }

        fori(i, m) {
            fori(j, m) {
                adj[i][j] = INT_MAX;
            }
        }

        for(auto vec: stops) {
            if(vec.size() > 1) {
            //this Stop connects 2 or more lines
                fori(i, vec.size()) {
                    fori(j, vec.size()) {
                        if(i != j) {
                            nl = mod(vec[i].wait, vec[j].wait);
                            //time difference from one line to another
                            if(nl < adj[vec[j].line][vec[i].line]) {
                                adj[vec[j].line][vec[i].line] = nl;
                            }
                        }
                    }
                }
            }
        }
        
        long long res = floydWarshall();

        if(res == INT_MAX) cout << "Hoy no vuelvo\n";
        else cout << res << endl;
    }

    return 0;
}
