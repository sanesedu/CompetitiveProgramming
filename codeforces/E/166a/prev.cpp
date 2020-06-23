
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define MOD 1000000007

#define N 10000000

using namespace std;

vector<vector<long long>> memo; 

long long solve(int pos, long long steps) {
    
    if(steps == 0) return (pos == 0) ? 1 : 0;
    if(steps == 1) return (pos != 0) ? 1 : 0;

    if(memo[pos][steps] != -1) return memo[pos][steps];

    long long res = 0;

    for(int i = 0; i < 4; ++i) {
        if(pos != i) res += (solve(i, steps-1) % MOD);
    }

    return (memo[pos][steps] = res);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long n;
    cin >> n;

    memo.assign(4, vector<long long>(n+1, -1));

    long long res = solve(0, n);

    cout << res << endl;

    return 0;
}
