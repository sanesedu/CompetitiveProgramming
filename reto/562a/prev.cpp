
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int cols, rows, frigs;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int c, int r) {
    return (c >= 0 && c < cols && r >= 0 && r < rows); 
}

void bfs(vector<vector<int>> &grid, int c, int r) {

    queue<pi> q;
    q.push({c, r});

    int dist[rows*cols+cols];
    memset(dist, -1, sizeof(dist));
    dist[r*cols+c] = 0;

    int newr, newc;

    while(!q.empty()) {
       
        pi cur = q.front();
        q.pop();

        fori(i, 4) {
            newc = cur.first + dx[i];
            newr = cur.second + dy[i];

            if(isValid(newc, newr) && dist[newr*cols+newc] == -1) {
                dist[newr*cols+newc] = 1 + dist[cur.second*cols+cur.first];;
                grid[newr][newc] += dist[newr*cols+newc];
                q.push({newc, newr});
            }
        } 

    }
}

void print(vector<vector<int>> grid) {
    
    fori(i, rows) {
        fori(j, cols) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int c, r;

    while(cin >> cols >> rows >> frigs) {
        
        if(cols == 0 && rows == 0 && frigs == 0) break;

        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        
        fori(i, frigs) {
            cin >> c >> r;
            --c;
            --r;
            bfs(grid, c, r);
        //    print(grid);
        }

        pi res;
        int val = INT_MAX;
        
        fori(i, rows) {
            fori(j, cols) {
                if(grid[i][j] < val) {
                    val = grid[i][j];
                    res.first = j;
                    res.second = i;
                } else if(grid[i][j] == val) {
                    if(i+j < res.first+res.second) {
                        res.first = j;
                        res.second = i; 
                    } else if(i+j == res.first+res.second) { 
                        if(res.first > j) {
                            res.first = j;
                            res.second = i;
                        }
                    }
                }
            }
        }
        
        cout << res.first+1 << " " << res.second + 1 << endl;
    }

    return 0;
}
