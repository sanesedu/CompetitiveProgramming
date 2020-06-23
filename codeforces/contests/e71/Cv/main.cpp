
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

    int t;
    cin >> t;

    long long n;

    long long a, b;
    string s;

    fori(i, t) {
        cin >> n >> a >> b >> s;
        
        long long dp[n+2][2] = {};

        dp[0][0] = b; //cost of first pillar
        dp[0][1] = 1e18; //first cannot be tall

        for(long long i = 1; i <= n; ++i) {
            if(s[i-1] == '1') {
                dp[i][0] = 1e18; //cannot be low
                dp[i][1] = dp[i-1][1] + 2*b + a; //if tall, prev must be tall and add current cost
                continue;
            }

            dp[i][0] = min(dp[i-1][0] + b + a, dp[i-1][1] + b + 2*a); //min cost staying low vs going down
            dp[i][1] = min(dp[i-1][1] + 2*b + a, dp[i-1][0] + 2*a + 2*b); //min cost staying up vs going up
        }
        
        cout << dp[n][0] << endl; //we must end low

    }

    return 0;
}
