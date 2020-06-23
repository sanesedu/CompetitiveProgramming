
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

bool isValid(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n;
    cin >> n;

    vector<vector<char>> mat(n, vector<char>(n));

    fori(i, n) {
        fori(j, n) {
            cin >> mat[i][j];
        }
    }

    int res = 0;
    int tmp;

    fori(i, n) {
        fori(j, n) {
            if(mat[i][j] == 'X') {
                tmp = 0;
                fori(k, 4) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(isValid(nx, ny, n) && mat[nx][ny] == 'X') ++tmp;
                }
                if(tmp == 4) ++res;
            } 
        }
    }

    cout << res << endl;

    return 0;
}
