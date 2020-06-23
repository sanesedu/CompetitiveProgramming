
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define MOD 31543

using namespace std;

int bigpow(int x, int n) {
    
    if(n == 0) return 1;
    
    int t = bigpow(x, n/2);
    if(n % 2 == 0) {
        return (t * t) % MOD;
    } else {
        return (((t * t) % MOD) * (x % MOD)) % MOD; 
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int x, n;

    while(cin >> x >> n) {
        if(x == 0 && n == 0) break;
    
        cout << bigpow(x, n) << endl;
    }

    return 0;
}
