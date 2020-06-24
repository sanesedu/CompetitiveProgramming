
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int memo[15][1 << 15];

int solve(vector<vector<int>> dist, int n, int pos, int mask) {
   
    if(mask == ((1 << n) -1)) {
        return dist[pos][0]; 
    }

    if(memo[pos][mask] != -1) return memo[pos][mask];

    int res = 10000000;

    for(int i = 0; i < n; ++i) {
        if(i != pos && (mask & (1 << i)) == 0) {
            res = min(res, dist[pos][i] + solve(dist, n, i, (mask | (1 << i)))); 
        }
    } 

    return (memo[pos][mask] = res);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, m, n, x, y, p;
    cin >> q;

    while(q--) {
        cin >> m >> n >> x >> y >> p;
        
        vector<pair<int, int>> points;
        points.pb(make_pair(x, y));
        
        fori(i, p) {
            cin >> x >> y;
            points.pb(make_pair(x, y));
        }
       
        vector<vector<int>> dist(p+1, vector<int>(p+1));

        fori(i, p+1) {
            fori(j, p+1) {
                dist[i][j] = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
                dist[j][i] = dist[i][j];
            }
        }

        memset(memo, -1, sizeof(memo));
        
        int res = solve(dist, p+1, 0, 1);
   
        cout << "The shortest path has length " << res << endl;
    }

    return 0;
}
