
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 110

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int t, r, c, m, n, w, a, b, even, odd;

int grid[N][N] = {0};
bool visited[N][N] = {false};

bool valid(int y, int x) {
    return y >= 0 && y < r && x >= 0 && x < c && grid[y][x] != -1;
}

bool allowed(int y, int x, int i, int j) {
    return (abs(y - i) == m && abs(x - j) == n) || (abs(y - i) == n && abs(x - j) == m);
}

void dfs(int y, int x) {
    
    visited[y][x] = true;

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(allowed(y, x, i, j) && valid(i, j)) {
                grid[y][x]++;
                if(!visited[i][j]) dfs(i, j);
            }
        }
    }
    
    if(grid[y][x] % 2 == 0) ++even;
    else ++odd;
}

void print() {
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    cin >> t;

    fori(j, t) {
        cin >> r >> c >> m >> n;
    
        cin >> w;

        memset(grid, 0, sizeof(grid));
        memset(visited, false, sizeof(visited));

        fori(i, w) {
            cin >> a >> b;
            grid[a][b] = -1; 
        }

        even = odd = 0;

//        print();

        dfs(0, 0);
        
//        print();

        cout << "Case " << j+1 << ": " << even << " " << odd << endl;

    }

    return 0;
}
