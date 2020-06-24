
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int n, m;

vector<int> res;
vector<vector<int>> graph;
vector<bool> visited;

void solve(int s) {
   
    visited[s] = true;

    vector<int>::iterator it;

    for(it = graph[s].begin(); it != graph[s].end(); ++it) {
        if(!visited[*it]) solve(*it);
    }

    res.pb(s);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int a, b;

    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;

        graph.assign(n, vector<int>());
        visited.assign(n, false);

        fori(i, m) {
            cin >> a >> b;
            --a;
            --b;
            graph[a].pb(b);
        }

        for(int i = 0; i < (int) graph.size(); ++i) {
            if(!visited[i]) solve(i);
        }

        reverse(all(res));

        vector<int>::iterator it;

        cout << *res.begin() + 1;

        it = res.begin();
        ++it;

        for(; it != res.end(); ++it) {
            cout << " " << *it + 1;
        }
        cout << endl;
        
        res.clear();

    }

    return 0;
}
