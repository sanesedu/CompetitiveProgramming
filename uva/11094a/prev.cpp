
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int m, n, a, b;

char mat[30][30];
bool vis[30][30];

char c1;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int i, int j) {
    return (i >= 0 && i < m && j >= 0 && j < n); 
}

int solve(int r, int c) {
   
    if(c == -1) c = n -1;
    if(c == n) c = 0;

    if(!isValid(r, c) || mat[r][c] != c1 || vis[r][c]) return 0;
    
    vis[r][c] = true;

    int res = 1;

    fori(k, 4) {
        res += solve(r + dx[k], c + dy[k]);
    }

    return res;
}

int main() {

    int res;

    while(cin >> m >> n) {
        fori(i, m) {
            fori(j, n) {
                cin >> mat[i][j];
            }
        }
        cin >> a >> b;

        c1 = mat[a][b];    

        memset(vis, false, sizeof(false));

        res = solve(a, b);
   
        fori(i, m) {
            fori(j, n) {
                if(mat[i][j] == c1) res = max(res, solve(i, j));
            }
        }

        cout << res << endl;
    } 

    return 0;
}
