
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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int p, r;

    string a, b;

    int network = 1;

    while(cin >> p >> r) {

        if(p == 0 && r == 0) break;

        map<string, int> names;

        int index = 0;

        vector<vector<int>> adj(p, vector<int>(p, INF));

        fori(i, r) {
            
            cin >> a >> b;

            if(names.find(a) == names.end()) {
                names[a] = index++;
            }

            if(names.find(b) == names.end()) {
                names[b] = index++;
            }

            adj[names[a]][names[b]] = 1;
            adj[names[b]][names[a]] = 1;
        }  

        //floyd warshall
        
        for(int k = 0; k < p; ++k) {
            for(int i = 0; i < p; ++i) {
                for(int j = 0; j < p; ++j) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        int mx = -1;

        for(int i = 0; i < p; ++i) {
            for(int j = i + 1; j < p; ++j) {
                mx = max(mx, adj[i][j]);
            }
        }

        cout << "Network " << network++ << ": ";

        if(mx == INF) {
            cout << "DISCONNECTED\n";
        } else {
            cout << mx << endl;
        }
        cout << endl;
    }

    return 0;
}
