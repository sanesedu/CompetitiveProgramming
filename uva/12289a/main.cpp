
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

string one = "one";

int solve(string s) {
    
    int diff1 = 0;
    int diff2 = 0;

    for(int i = 0; i < 3; ++i) {
        if(s[i] != one[i]) ++diff1; 
    }

    if(diff1 <= 1) return 1;

    return 2;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string s;
    int t;
    cin >> t;

    while(t--) {
        cin >> s;
        if(s.length() > 3) {
            cout << 3 << endl;
        } else {
            cout << solve(s) << endl;
        }
    }

    return 0;
}
