
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

long long connect(vector<vector<int>> graph, int s, int n) {

    queue<int> q;
    q.push(s);

    long long res = 1;

    vector<bool> visited(n, false);

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, n, m, a, b;
    cin >> q;

    while(q--) {
        cin >> n >> m;

        vector<vector<int>> graph(n);

        fori(i, n) {
            cin >> a >> b;
            graph[a-1].pb(b);
            graph[b-1].pb(a);
        }
    }

    return 0;
}
