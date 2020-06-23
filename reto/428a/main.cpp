
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int solve(int n) {
    
    if(n == 0) return 0;

    if(n % 5 == 4) {
        return 1 + solve(n/5);
    } else {
        return solve(n/5);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, n, res;
    cin >> q;

    while(q--) {
        cin >> n;
        res = solve(n);
        if(res >= 2) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}
