
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 120

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int mat[N][N];

    int t, r, c, k, area, cost, ta, tc;
    cin >> t;

    fori(i, t) {
        
        cin >> r >> c >> k;

        fori(j, r) {
            fori(k, c) {
                cin >> mat[j][k];
                if(j > 0) mat[j][k] += mat[j-1][k];
                if(k > 0) mat[j][k] += mat[j][k-1];
                if(j > 0 && k > 0) mat[j][k] -= mat[j-1][k-1];
            }
        }

        area = INT_MIN;
        cost = INT_MAX;

        fori(a1, r) {
            fori(b1, c) {
                for(int a2 = a1; a2 < r; ++a2) {
                    for(int b2 = b1; b2 < c; ++b2) {
                        
                        ta = (a2 - a1 + 1) * (b2 - b1 + 1);

                        tc = mat[a2][b2];
                        if(a1 > 0) tc -= mat[a1-1][b2];
                        if(b1 > 0) tc -= mat[a2][b1-1];
                        if(a1 > 0 && b1 > 0) tc += mat[a1-1][b1-1];

                        if(tc <= k) {
                            if(ta > area) {
                                area = ta;
                                cost = tc;
                            } else if(ta == area && tc < cost) {
                                cost = tc;
                            }
                        }
                    }
                }
            }
        }

        if(area == INT_MIN && cost == INT_MAX) {
            area = cost = 0;
        }

        printf("Case #%d: %d %d\n", i+1, area, cost);
    }
    
    return 0;
}
