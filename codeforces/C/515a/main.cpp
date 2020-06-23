
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    map<int, int> m;

    m[2] = 2;
    m[3] = 3;
    m[4] = 322;
    m[5] = 5;
    m[6] = 53;
    m[7] = 7;
    m[8] = 7222;
    m[9] = 7332;

    int n;
    cin >> n;

    string s;
    cin >> s;

    string res = "";

    fori(i, n) {
        if((s[i] - '0') > 1) {
            res += to_string(m[(s[i] - '0')]);
        }
    }

    sort(res.begin(), res.end());

    reverse(res.begin(), res.end());

    cout << res << endl;

    return 0;
}
