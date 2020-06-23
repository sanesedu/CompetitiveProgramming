
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isValid(int i, int j, int h, int w) {
    return (i >= 0 && i < h && j >= 0 && j < w);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int w, h, tmp;

    long long res, count;

    while(cin >> w >> h) {
        if(w == 0 && h == 0) break;

        vector<vector<char>> mat(h, vector<char>(w));

        fori(i, h) {
            fori(j, w) {
                cin >> mat[i][j];
            }
            cin.ignore();
        }

        res = 0;

        fori(i, h) {
            fori(j, w) {
                if(mat[i][j] == '-') {
                    count = 0;
                    fori(k, 8) {
                        if(isValid(i + dx[k], j + dy[k], h, w) && mat[i + dx[k]][j + dy[k]] == '*') ++count;
                    }
                    if(count >= 6) ++res;
                } 
            }
        }

        cout << res << endl;
    }

    return 0;
}
