
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define MOD 1000000

using namespace std;

long long memo[110][110];

long long solve(int n, int k) {
    
    if(n == 0 | k == 1) return 1;

    if(memo[n][k] != -1) return memo[n][k];

    long long res = 0;

    for(int i = 0; i <= n; ++i) {
        res += solve(n - i, k - 1) % MOD;
    }

    return memo[n][k] = res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, k;

    while(cin >> n >> k) {
        if(n == 0 && k == 0) break;
        
        memset(memo, -1, sizeof(memo)); 
        cout << solve(n, k) % MOD << endl;        
    }

    return 0;
}
