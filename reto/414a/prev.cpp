
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 1000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vi primes;

void sieve() {

    bitset<N> bs;

    for(int i = 2; i < N; ++i) {
        if(!bs[i]) {
            for(int j = 2*i; j < N; j += i) bs[j] = 1;
            primes.pb(i);
        }
    }
}

int solve(int n) {

    int s = sqrt(n);

    if(s * s == n) return 1;

    int res = 1;

    int pow;

    for(auto it = primes.begin(); it != primes.end() && n > 1; ++it) {
        if(n % *it == 0) {
            pow = 0;
            while(n % *it == 0) {
                n /= *it;
                ++pow;
            }
            if(pow % 2) res *= *it;
        }
    }

    if(n > 1) res *= n;

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    sieve();

    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
    
        cout << solve(n) << endl; 
    }

    return 0;
}
