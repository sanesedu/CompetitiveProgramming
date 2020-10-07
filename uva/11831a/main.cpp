
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
typedef pair<int, int> ii;
    
int rows, columns, inst;
int dir;
pair<int, int> pos;

map<char,int> dirs = {{'N', 0}, {'L', 1}, {'S', 2}, {'O', 3}};
map<char, int> vals = {{'.', 0}, {'*', 1}, {'#', 2}};

int y[4] = {-1, 0, 1, 0};
int x[4] = {0, 1, 0, -1};

int process(vector<vector<int>> &arena, char q) {
    if(q == 'D') {
        dir = (dir + 1) % 4; 
    } else if(q == 'E') {
        dir = ((dir + 4) - 1) % 4; 
    } else {
        int newy = pos.first + y[dir];
        int newx = pos.second + x[dir];
        
        if(newy >= 0 && newy < rows && newx >= 0 && newx < columns && arena[newy][newx] != 2) {
            pos.first = newy;
            pos.second = newx;
            if(arena[newy][newx] == 1) {
                arena[newy][newx] = 0;
                return 1;
            }
        }
    }

    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string line;
    char q;
    int res;

    while(cin >> rows >> columns >> inst, rows || columns || inst) {
        vector<vector<int>> arena(rows, vector<int>(columns, 0)); 

        fori(i, rows) {
            cin >> line;
            fori(j, columns) {
                if(vals.find(line[j]) != vals.end()) {
                    arena[i][j] = vals[line[j]];
                } else {
                    arena[i][j] = 0;
                    pos.first = i;
                    pos.second = j;
                    dir = dirs[line[j]];
                }
            }
        }
        
        res = 0;

        fori(i, inst) {
            cin >> q;
            res += process(arena, q);
        }

        cout << res << endl;
    }

    return 0;
}
