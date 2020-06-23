
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define MOD 1000000007
#define N 10010

using namespace std;

long long memo[N];

long long solve(long long n) {
    
    if(n == -1) return 1; //takes into account extra pulse after last digit
    if(n < -1) return 0;

    if(memo[n] != -1) return memo[n];

    long long res = 0;

    for(int i = 1; i <= 10 && n >= i; ++i) { //possible number of pulses per digit
        res = (res % MOD + solve(n - i - 1) % MOD) % MOD; //-1 for pulse between between digits
    }
    
    return (memo[n] = res);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t;
    cin >> t;

    long long n;

    memset(memo, -1, sizeof(memo));

    while(t--) {
        cin >> n;
    
        cout << solve(n)%MOD << endl;
    }

    return 0;
}
