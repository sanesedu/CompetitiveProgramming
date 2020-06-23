
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int sieve(int n) {
    
    bool primes[n+1];

    memset(primes, true, sizeof(primes));

    primes[0] = false;
    primes[1] = false;

    for(int i = 2; i*i <= n; ++i) {
        if(primes[i] == true) {
            for(int j = i*i; j <= n; j += i) {
               primes[j] = false; 
            }
        }
    }

    int prev = 2;

    int res = 0;

    for(int i = 3; i <= n; ++i) {
        if(primes[i]) {
            if(i + prev + 1 <= n && primes[i+prev+1]) ++res;
            prev = i;
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, k;
    cin >> n >> k;

    int res = sieve(n);

    if(res >= k) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
