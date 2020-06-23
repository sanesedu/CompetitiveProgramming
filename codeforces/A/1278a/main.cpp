
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

    int t;
    cin >> t;

    string s, h;

    bool b;

    while(t--) {
        cin >> s >> h;
        
        vector<int> cs(26, 0);
    
        b = false;

        fori(i, s.length()) ++cs[s[i] - 'a'];
    
        for(int i = 0; i < (int) h.length() && !b; ++i) {
            vector<int> ch(26, 0);
            for(int j = i; j < (int) h.length() && !b; ++j) {
                ++ch[h[j] - 'a'];
                if(ch == cs) {
                    b = true;
                }
            }
        }

        if(b) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
