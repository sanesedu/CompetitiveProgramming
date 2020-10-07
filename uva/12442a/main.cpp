
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 50010

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<bool> visited(N, false);
vector<int> graph(N, 0);
vector<int> path_len(N, 0);

int dfs(int i) {
    visited[i] = true;
    int len = 1;

    if(!visited[graph[i]]) {
        len = dfs(graph[i]) + 1;
    }

    visited[i] = false;
    return path_len[i] = len;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, n, node, res, s, d;
    cin >> t;

    fori(j, t) {
        cin >> n;
        
        fori(i, n) {
            cin >> s >> d;
            graph[s] = d;
            visited[s] = false;
            path_len[s] = 0;
        }
        
        res = -1;
        node = -1;

        for(int i = 1; i <= n; ++i) {
            if(path_len[i] == 0) dfs(i); 
            if(path_len[i] > res) {
                res = path_len[i];
                node = i;
            }
        }

        cout << "Case " << j+1 << ": " << node << endl;
    }

    return 0;
}
