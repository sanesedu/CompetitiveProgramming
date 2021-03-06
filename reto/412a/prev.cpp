
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

int col, row;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int y, int x) {
    return (y > 0 && y < row-1 && x > 0 && x < col-1);
}

bool bfs(vector<vector<char>> &mat, int i, int j) {
    
    queue<pi> q;
    q.push({i, j});
    
    while(!q.empty()) {
        
        pi cur = q.front();
        q.pop();
        
        fori(k, 4) {
            int newy = cur.first + dy[k];
            int newx = cur.second + dx[k];
            
            if(!isValid(newy, newx)) return false;

            if(mat[newy][newx] == '.') {
                q.push({newy, newx});
                mat[newy][newx] = '#';
            }
        }
    }

    return true;
}

void print(vector<vector<char>> mat) {
    
    fori(i, row) {
        fori(j, col) {
            cout << mat[i][j];
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

    bool found;

    while(cin >> col >> row) {
        
        vector<vector<char>> mat(row, vector<char>(col));

        fori(i, row) {
            fori(j, col) {
                cin >> mat[i][j];
            }
        }
      
        found = false;

        for(int i = 1; i < row-1 && !found; ++i) {
            for(int j = 1; j < col-1 && !found; ++j) { 
                if(mat[i][j] == '.') {
                    int count = 0;
                    fori(k, 4) {
                        if(mat[i+dy[k]][j+dx[k]] == 'X') ++count;
                    }
                    if(count == 4) found = true;
                    else if(count >= 2) { //we only carry out the search for the corners
                        mat[i][j] = '#';
                        found = bfs(mat, i, j);
//                        print(mat);
                    }
                }
            }
        }

        if(found) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}
