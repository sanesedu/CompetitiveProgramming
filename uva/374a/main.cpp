
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

long long big_mod(long long b, long long p, long long m) {

    if(p == 0) return 1;
    
    if(p % 2 == 1) {
        long long part1 = b % m;
        long long part2 = big_mod(b, p-1, m);
        return (part1 * part2) % m;
    } else {
        long long half = big_mod(b, p/2, m);
        return (half * half) % m;
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long b, p, m;

    while(cin >> b >> p >> m) {
        cout << big_mod(b, p, m) << endl;
    }

    return 0;
}
