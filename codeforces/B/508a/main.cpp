
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
    
    string s;
    cin >> s;

    int l = s.length();
    int f = -1;

    fori(i, l) {
        if((s[i]-'0') % 2 == 0) {
            if(s[i] < s[l-1]) {
                swap(s[i], s[l-1]);
                cout << s << endl;
                return 0;
            }
            f = i;
        }
    }

    if(f == -1) cout << -1 << endl;
    else {
        swap(s[f], s[l-1]);
        cout << s << endl;
    }

    return 0;
}
