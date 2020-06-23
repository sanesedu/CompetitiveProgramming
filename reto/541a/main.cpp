#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

long long gcd(long long a, long long b) {
    if(a == 0) return b;
    else if(b == 0) return a;
    else if(a > b) return gcd(a % b, b);
    else return gcd(a, b % a);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long a, b, c, g, res;

    while(cin >> a >> b >> c) {
        if(a == 0 && b == 0 && c == 0) {
            break;
        }

        g = gcd(a, gcd(b, c));
        res = (a+b+c) / g;

        cout << res << "\n";

    }

    return 0;
}
