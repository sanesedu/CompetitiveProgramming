
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int memo[110][110];

int solve(string s, int l, int r) {

    if(l > r) return 0;
    if(l == r) return 1;

    if(memo[l][r] != -1) return memo[l][r];

    int res;

    if(s[l] == s[r]) {
        res = 2 + solve(s, l+1, r-1);
    } else {
        res = max(solve(s, l+1, r), solve(s, l, r-1));
    }

    return (memo[l][r] = res);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string s;

    while(cin >> s) {
        memset(memo, -1, sizeof(memo));

        int l = s.length();

        cout << l - solve(s, 0, l-1) << endl;
    }

    return 0;
}
