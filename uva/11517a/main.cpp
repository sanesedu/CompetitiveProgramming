
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 110
#define T 20010

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int dp[N][T];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int t, total, n, res, num;
    cin >> t;

    while(t--) {
        cin >> total >> n;
        
        int coins[n+1];

        for(int i = 1; i <= n; ++i) cin >> coins[i];
        
        fori(i, N) {
            fori(j, T) {
                dp[i][j] = T;
            }
        }

        fori(i, N) dp[i][0] = 0;

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < T; ++j) {
                if(coins[i] <= j) {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j-coins[i]]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        res = num = 0;

        for(int i = total; i < T; ++i) {
            num = dp[n][i];
            res = i;
            if(num != T) break;
        }
        
        cout << res << " " << num << endl;
    }

    return 0;
}
