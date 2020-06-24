
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

vector<vector<int>> graph;

vector<int> match, visited;

int augment(int s) {
    
    if(visited[s]) return 0;

    visited[s] = 1;

    for(int j = 0; j < (int) graph[s].size(); ++j) {
        int r = graph[s][j];
        if(match[r] == -1 || augment(match[r])) {
            match[r] = s;
            return 1;
        }
    }

    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, val;
    cin >> t;

    fori(k, t) {
       
        int bolts, nuts;
        cin >> bolts >> nuts;
        
        graph.assign(bolts, vector<int>());

        fori(i, bolts) {
            fori(j, nuts) {
                cin >> val;
                if(val) graph[i].pb(bolts + j);  
            }
        }

        int mcbm = 0;
        
        match.assign(bolts + nuts, -1);

        fori(i, bolts) { //size of left set
            visited.assign(bolts, 0);
            mcbm += augment(i);
        }

        cout << "Case " << k + 1 << ": a maximum of " << mcbm << " nuts and bolts can be fitted together" << endl;
    }

    return 0;
}
