
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

void fw(vector<vector<long long>> dist, int n) {

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        } 
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            if(j != i+1) cout << " ";
            cout << dist[i][j];
        }
        if(i < n-1) cout << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n;

    while(cin >> n) {
        vector<vector<long long>> dist(n, vector<long long>(n,INF));
        fori(i, n-1) {
            for(int j = i+1; j < n; ++j) {
                cin >> dist[i][j]; 
            }
        }

        fw(dist, n); 
    }

    return 0;
}
