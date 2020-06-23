
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define MOD 1000000007

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long n;
    cin >> n;
    
    vector<long long> dp(n+1, 0);

    dp[1] = 0;
    dp[2] = 3;

    for(int i = 3; i <= n; ++i) {
        dp[i] = (2 * dp[i-1] + 3 * dp[i-2]) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}
