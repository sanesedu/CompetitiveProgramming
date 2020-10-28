
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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, a, b, c;
    ll tmp, res, sum;

    cin >> t;

    while(t--) {
        
        cin >> a >> b >> c;
    
        ll mat[a][b][c];

        fori(i, a) {
            fori(j, b) {
                fori(k, c) {
                    cin >> tmp;
                    if(i > 0) tmp += mat[i-1][j][k];
                    if(j > 0) tmp += mat[i][j-1][k];
                    if(k > 0) tmp += mat[i][j][k-1];
                    if(i > 0 && j > 0) tmp -= mat[i-1][j-1][k];
                    if(j > 0 && k > 0) tmp -= mat[i][j-1][k-1];
                    if(i > 0 && k > 0) tmp -= mat[i-1][j][k-1];
                    if(i > 0 && j > 0 && k > 0) tmp += mat[i-1][j-1][k-1];
                    mat[i][j][k] = tmp;
                }
            }
        }

        res = INT_MIN;

        fori(i1, a) {
            fori(j1, b) {
                fori(k1, c) {
                    for(int i2 = i1; i2 < a; ++i2) {
                        for(int j2 = j1; j2 < b; ++j2) {
                            for(int k2 = k1; k2 < c; ++k2) {
                                sum = mat[i2][j2][k2];
                                if(i1 > 0) sum -= mat[i1-1][j2][k2];
                                if(j1 > 0) sum -= mat[i2][j1-1][k2];
                                if(k1 > 0) sum -= mat[i2][j2][k1-1];
                                if(i1 > 0 && j1 > 0) sum += mat[i1-1][j1-1][k2];
                                if(i1 > 0 && k1 > 0) sum += mat[i1-1][j2][k1-1];
                                if(j1 > 0 && k1 > 0) sum += mat[i2][j1-1][k1-1];
                                if(i1 > 0 && j1 > 0 && k1 > 0) sum -= mat[i1-1][j1-1][k1-1];
                                res = max(res, sum); 
                            }
                         }
                    }
                }
             }
        }
        
        cout << res << endl;

        if(t) cout << endl;
    }

    return 0;
}
