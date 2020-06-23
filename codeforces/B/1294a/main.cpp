
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
    
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        
        vector<pair<int, int>> pos(n);

        fori(i, n) {
            cin >> pos[i].first >> pos[i].second;
        }

        sort(all(pos));

        pair<int, int> now;
        now.first = 0;
        now.second = 0;

        bool flag = false;

        vector<pair<int, int>>::iterator it;
    
        string s = "";

        for(it = pos.begin(); it != pos.end(); ++it) {
            if(it->first >= now.first && it->second >= now.second) {
                for(int i = 0; i < (it->first - now.first); ++i) s.append("R");
                for(int i = 0; i < (it->second - now.second); ++i) s.append("U");
                now = *it;
            } else {
                flag = true;
                break;
            }
        }

        if(flag) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << s << endl;
        }
    }

    return 0;
}
