
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 1100

using namespace std;

set<int> primes;

void sieve() {
    
    bitset<N> bs;

    primes.insert(1);

    for(int i = 2; i < N; ++i) {
        if(!bs[i]) {
            for(int j = i * i; j < N; j += i) bs[j] = 1;
            primes.insert(i);
        }
    }
}

int getval(string s) {
    
    int len = s.length();

    int res = 0;

    fori(i, len) {
        if(isupper(s[i])) {
            res += (s[i] - 'A' + 27);
        } else {
            res += (s[i] - 'a' + 1);
        }
    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string s;

    sieve();

    while(cin >> s) {
        
        int val = getval(s);
    
        if(primes.find(val) == primes.end()) cout << "It is not a prime word." << endl;            
        else cout << "It is a prime word." << endl; 
    }

    return 0;
}
