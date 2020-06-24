
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

long long solve(long long n, long long m) {
    long long num, den;
    if(m > (n - m)) {
        num = 1;
        for(long long i = (n - m); i <= n; ++i) {
            num *= i;
        }

        den = 1;
        for(long long i = 2; i <= m; ++i) {
            den *= i;
        }

        cout << num << " " << den << endl;

        return num/den; 

    } else { 
        num = 1;
        for(long long i = m; i <= n; ++i) {
            num *= i;
        }

        den = 1;
        for(long long i = 2; i <= (n-m); ++i) {
            den *= i;
        }

        cout << num << " " << den << endl;
        return num/den; 
        
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long n, m;

    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        cout << n << " things taken " << m << " at a time is " << solve(n, m) << " exactly." << endl;
    }

    return 0;
}
