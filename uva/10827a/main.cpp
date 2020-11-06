
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 100

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int mat[N*2][N*2];

    int t, n, res, cur;
    cin >> t;

    while(t--) {
        cin >> n;

        fori(i, 2*n) {
            fori(j, 2*n) {
                if(i < n && j < n) {
                    cin >> mat[i][j];
                    mat[i+n][j] = mat[i][j+n] = mat[i+n][j+n] = mat[i][j];
                }

                if(i > 0) mat[i][j] += mat[i-1][j];
                if(j > 0) mat[i][j] += mat[i][j-1];
                if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
            }
        }
        
        res = INT_MIN;

        fori(i1, n) {
            fori(j1, n) {
                for(int i2 = i1; i2 < i1+n; ++i2) {
                    for(int j2 = j1; j2 < j1+n; ++j2) {
                        cur = mat[i2][j2];
                        if(i1 > 0) cur -= mat[i1-1][j2];
                        if(j1 > 0) cur -= mat[i2][j1-1];
                        if(i1 > 0 && j1 > 0) cur+= mat[i1-1][j1-1];
                        
                        res = max(res, cur);
                    } 
                }
            }
        }
        
        cout << res << endl;
    }

    return 0;
}
