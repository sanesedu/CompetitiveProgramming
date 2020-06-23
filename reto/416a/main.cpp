
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

    int n, d, m, y;
    string s;

    while(cin >> n) {
        if(n == 0) break;

        map<string, int> mp;

        bool flag = false;

        fori(i, n) {
            scanf("%d/%d/%d", &d, &m, &y);
            s = to_string(d) + "-" + to_string(m);
            mp[s]++;
            if(mp[s] > 1) flag = true;
        }

        if(flag) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}
