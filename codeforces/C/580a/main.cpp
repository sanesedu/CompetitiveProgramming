
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int res = 0, m;
map<int, bool> visited;
map<int, int> cats;
map<int, vector<int>> graph;

void dfs(int source, int c) {

    //cout << "source: " << source << ", c: " << c << ", size: " << graph[source].size() << endl;

    if(c > m) return;

    visited[source] = true;

    vector<int>::iterator it;

    for(it = graph[source].begin(); it != graph[source].end(); ++it) {
        if(!visited[*it]) {
            if(cats[*it]) dfs(*it, c+1);
            else dfs(*it, 0);
        }
    }
    
    visited[source] = true;

    if(graph[source].size() == 1 && source != 1) ++res; 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, a, b;
    cin >> n >> m;

    fori(i, n) {
        cin >> a;
        cats[i+1] = a;
        visited[i+1] = false;
    }

    fori(i, n-1) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    //vector<int>::iterator it;
    
    /*fori(i, n) {
        cout << "vertex = " << i+1 << "  : ";
        for(it = graph[i+1].begin(); it != graph[i+1].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }*/

    dfs(1, cats[1]);

    cout << res << endl;

    return 0;
}
