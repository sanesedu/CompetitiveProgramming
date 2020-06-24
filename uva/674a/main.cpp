
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 7500
#define INF 100000000

using namespace std;

int coins[] = {50, 25, 10, 5, 1};

int dp[7500];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for(int i = 0; i < 5; ++i) {
        for(int j = 1; j < 7500; ++j) {
            if(j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }

    int n;

    while(cin >> n) {
        cout << dp[n] << endl;
    }

    return 0;
}
