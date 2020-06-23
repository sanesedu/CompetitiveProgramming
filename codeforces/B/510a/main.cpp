
#include <iostream>
#include <cstring>

using namespace std;

bool visited[51][51];
string board[51];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};
bool cycle = false;
int n, m;

void dfs(int i, int j, int fri, int frj, char color) {
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    
    if(board[i][j] != color) return;

    if(visited[i][j]) {
        cycle = true;
        return;
    }

    visited[i][j] = true;

    for(int h = 0; h < 4; ++h) { //move 4 possible directions
        int ni = i + mx[h]; 
        int nj = j + my[h];

        if(ni == fri && nj == frj) continue;
        dfs(ni, nj, i, j, color);
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; ++i) cin >> board[i];

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!visited[i][j]) {
                dfs(i, j, -1, -1, board[i][j]);
            }
        }
    }

    if(cycle) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
