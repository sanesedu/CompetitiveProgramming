
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int graph[110][110];
int f[110][110];

int visited[110];

int n;

void dfs(int s, int stop) {
    
    if(s == stop) return;

    visited[s] = 1;

    for(int i = 0; i < n; ++i) {
        if(graph[s][i] && !visited[i]) {
            dfs(i, stop);
        } 
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t;
    cin >> t;

    fori(k, t) {
        cin >> n;
        
        fori(i, n) {
            fori(j, n) {
                cin >> graph[i][j];
            }
        }

        int used[110] = {};

        memset(visited, 0, sizeof(visited));
        
        dfs(0, -1);
       
        fori(i, n) used[i] = visited[i]; 

        fori(i, n) {
            memset(visited, 0, sizeof(visited));
            dfs(0, i);
            fori(j, n) {
                if(used[j] && !visited[j]) { //visited at first but not now
                    f[i][j] = 1; 
                } else {
                    f[i][j] = 0;
                }
            }
            f[i][i] = used[i]; //if node not visited at first, it cannot be dominated
        }
        
        cout << "Case " << k+1 << ":" <<endl;
        
        cout << "+";
        for(int j = 1; j < 2*n; ++j) cout << "-";
        cout << "+\n";

        fori(i, n) {
           
            fori(j, n) {
                cout << "|";
                if(f[i][j]) cout << "Y";
                else cout << "N";
            }
            cout << "|\n";
            
            cout << "+";
            for(int j = 1; j < 2*n; ++j) cout << "-";
            cout << "+\n";
        }

    }

    return 0;
}
