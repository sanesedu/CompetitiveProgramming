
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

const long long MOD = 1000000007;
const int SIZE = 100005;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int t, k, a, b;
    cin >> t >> k;

    long long dp[SIZE] = {};
    long long res[SIZE] = {};

    fori(i, k) dp[i] = 1;
    //the words up to k length can only have a possible arrangement, all 1's

    forb(i, k, SIZE-1) dp[i] = (dp[i-1] + dp[i-k]) % MOD;
    //for every possible string length we compute the number of possible arrangements of 
    //size k, using the previous amount of arrangements

    forb(i, 1, SIZE-1) res[i] = (res[i-1] + dp[i]) % MOD;
    //accumulate number of arrangements

    fori(i, t) {
        cin >> a >> b;
        cout << ((res[b] - res[a-1]) % MOD + MOD) % MOD << endl; 
    }

    return 0;
}
