
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

long long solve(long long n, long long k) {
    
    if(n == 1) return 0;

    return (solve(n-1, k) + k) % n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q;
    cin >> q;

    long long n, k;

    int index = 0;

    while(q--) {
        cin >> n >> k;
        cout << "Case " << ++index << ": " << solve(n, k) + 1 << endl;
    }

    return 0;
}
