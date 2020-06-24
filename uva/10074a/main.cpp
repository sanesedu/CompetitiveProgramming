
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int maxsum(vector<vector<int>> mat, int m, int n) {

    int temp[m];

    int res = -100000000;

    int cur;

    for(int left = 0; left < n; ++left) {
        
        memset(temp, 0, sizeof(temp));

        for(int right = left; right < n; ++right) {
            
            fori(i, m) {
                temp[i] += mat[i][right];
            }

            cur = 0;

            for(int i = 0; i < m; ++i) {
                cur += temp[i];
                res = max(res, cur);
                if(cur < 0) cur = 0;
            }
        }
    }
    
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int m, n, t;

    while(cin >> m >> n) {
        if(m == 0 && n == 0) break;

        vector<vector<int>> mat(m, vector<int>(n));
    
        fori(i, m) {
            fori(j, n) {
                cin >> t;
                if(t == 0) mat[i][j] = 1;
                else mat[i][j] = -10000000;
            }
        }

        int res = maxsum(mat, m, n);

        cout << max(0, res) << endl;
    }

    return 0;
}
