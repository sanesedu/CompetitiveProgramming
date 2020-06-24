
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

set<long long> primes;

void sieve() {
    
    vector<bool> bs(N, true);
    
    bs[0] = bs[1] = false;

    for(long long i = 2; i < N; ++i) {
        if(bs[i]) {
            for(long long j = i * i; j < N; j += i) {
                bs[j] = false;
            }
            primes.insert(i);
        }
    }
}

void solve(long long n) {
    
    set<long long>::iterator it;

    for(it = primes.begin(); it != primes.end(); ++it) {
        if(primes.count(n - *it)) {
            cout << n << " = " << *it << " + " << n - *it << endl;  
            return;
        }
    }
    
    cout << "Goldbach's conjecture is wrong." << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    sieve();

    long long n;

    while(cin >> n) {
        if(n == 0) break;
        solve(n); 
    }

    return 0;
}
