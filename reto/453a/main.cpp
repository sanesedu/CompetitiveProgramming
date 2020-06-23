
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

vector<bool> visited(20000);
vector<vector<int>> graph(20000);

void bfs(int s) {
    
    queue<int> q;
    q.push(s);

    visited[s] = true;

    while(!q.empty()) {
        int t = q.front();
        q.pop();

        vector<int>::iterator it;

        for(it = graph[t].begin(); it != graph[t].end(); ++it) {
            if(!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int e, r, a, b;

    while(cin >> e) {
        if(e == 0) break;

        cin >> r;
       
        fori(i, e+1) {
            graph[i].clear();
            visited[i] = false;
        }

        fori(i, r) {
            cin >> a >> b;
            --a;
            --b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        bfs(0); 
   
        bool flag = false;

        fori(i, e) {
            if(!visited[i]) {
                flag = true;
                break;
            }
        }

        if(flag) cout << "FALTA ALGUNA\n";
        else cout << "TODAS\n";
    }

    return 0;
}
