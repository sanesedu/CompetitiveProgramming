
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define MOD 2000000011

using namespace std;

long long modpow(long long a, long long b) {
    
    long long res = 1;

    while(b) {
        if(b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q;
    long long n, res;
    cin >> q;

    int index = 1;

    while(q--) {
        cin >> n;
        if(n == 1) {
            res = 1;
        } else {
            res = modpow(n, n - 2);
        }
        cout << "Case #" << index++ << ": " << res << endl;
    }

    return 0;
}
