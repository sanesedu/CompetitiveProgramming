
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

    int n;
    cin >> n;

    string s, t;

    while(n--) {
        cin >> s >> t;
    
        vector<pair<char, int>> ps, pt;
    
        char prev = s[0];
        int count = 1;

        for(int i = 1; i <= (int) s.length(); ++i) {
            if(s[i] != prev) {
                ps.pb({prev, count});
                count = 1;
                prev = s[i];
            } else {
                ++count;
            }
        } 
       
        prev = t[0];
        count = 1;

        for(int i = 1; i <= (int) t.length(); ++i) {
            if(t[i] != prev) {
                pt.pb({prev, count});
                count = 1;
                prev = t[i];
            } else {
                ++count;
            }
        } 
   
        bool b = (ps.size() == pt.size());
       
        if(b)  {
            for(int i = 0; i < (int) ps.size() && b; ++i) {
                if(ps[i].first != pt[i].first || ps[i].second > pt[i].second) b = false;
            }
        }

        if(b) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
