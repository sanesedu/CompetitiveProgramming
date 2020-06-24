
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n;
    
    while(cin >> n) {

        int dp[n][n];

        fori(i, n) {
            fori(j, n) {
                cin >> dp[i][j];
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
                if(i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1]; //avoid double count
            }
        }

        int res = -127 * 100 * 100;

        int temp;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) { //first coordinates
                for(int l = i; l < n; ++l) {
                    for(int k = j; k < n; ++k) { //end coordinates
                        temp = dp[l][k];
                        if(i > 0) temp -= dp[i-1][k];
                        if(j > 0) temp -= dp[l][j-1];
                        if(i > 0 && j > 0) temp += dp[i-1][j-1];
                        res = max(res, temp);
                    }
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
