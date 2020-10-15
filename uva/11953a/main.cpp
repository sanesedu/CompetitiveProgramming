
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

int grid[N][N];

int v[4] = {1, 0, -1, 0};
int h[4] = {0, 1, 0, -1};

map<char, int> val = {{'@', -1}, {'.', 0}, {'x', 1}};

int n;

bool valid(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

void solve(int y, int x) {
    
    if(grid[y][x] == 0) return; 
    
    grid[y][x] = 0;

    fori(i, 4) {
        int newy = y + v[i];
        int newx = x + h[i];
    
        if(valid(newy, newx)) {
            solve(newy, newx); 
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, res;
    cin >> t;

    char c;

    fori(i, t) {
        cin >> n;

        fori(j, n) {
            fori(k, n) {
                cin >> c;
                grid[j][k] = val[c];
            }
        }

        res = 0;

        fori(j, n) {
            fori(k, n) {
                if(grid[j][k] == 1) {
                    ++res;
                    solve(j, k);
                }
            }
        }

        cout << "Case " << i+1 << ": " << res << endl;
    }

    return 0;
}
