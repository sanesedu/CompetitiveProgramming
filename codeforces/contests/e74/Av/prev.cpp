
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

map<long long, bool> primes;

bool is_prime(long long n) {

    if(primes.find(n) != primes.end()) {
        return primes[n];
    }

    if(n <= 1) return false;
    else if(n == 2) return true;
    else if(n % 2 == 0) return false;
    else {

        for(long long i = 3; i * i <= n; i += 2) {
            if(n % i == 0) {
                primes[n] = false;
                return false;
            }
        }
        
        primes[n] = true;
        return true;
    }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n;
    long long x, y;
    cin >> n;

    fori(i, n) {
        cin >> x >> y;
        
        long long diff = x - y;

        if(diff % 2 == 0) {
            cout << "YES" << endl;
        } else {

            bool f = false;

            for(long long i = 1; i * i <= diff; i += 2) {
                if(diff % i == 0) {
                    if(is_prime(i) || is_prime(diff/i)) {
                        f = true;
                        break;
                    }
                }
            }

            if(f) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
