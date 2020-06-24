
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 30010

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long dp[N];

    int coins[] = {1, 5, 10, 25, 50};

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for(int c = 0; c < 5; ++c) {
        for(int val = 1; val < N; ++val) {
            if(val >= coins[c]) {
                dp[val] += dp[val - coins[c]];
            }
        }
    }

    int n;

    while(cin >> n) {
        if(dp[n] > 1) cout << "There are " << dp[n] << " ways to produce " << n << " cents change." << endl;
        else cout << "There is only " << dp[n] << " way to produce " << n << " cents change." << endl;
    }

    return 0;
}
