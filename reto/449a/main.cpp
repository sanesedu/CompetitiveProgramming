
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

string s;

int memo[100][100];

int solve(int l, int r) {
    
    if(l == r) return 1;
    if(l > r) return 0;

    if(memo[l][r] != -1) return memo[l][r];

    char c = s[l];

    int laux = 0;
    int raux = 0;
    
    for(int i = l; i < (int) s.length(); ++i) {
        if(s[i] != c) break;
        else ++laux;
    }

    c = s[r];

    for(int i = r; i > 0; --i) {
        if(s[i] != c) break;
        else ++raux;
    }
    
    if(s[l] == s[r]) return (memo[l][r] = solve(l + laux, r - raux) + 1);
    
    return (memo[l][r] = min(solve(l + laux, r), solve(l, r - raux)) + 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);


    while(cin >> s) {
        memset(memo, -1, sizeof(memo));
        int res = solve(0, s.length() - 1);
        cout << res << endl;
    }

    return 0;
}
