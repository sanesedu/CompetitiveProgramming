
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    string line, res;
    int best;

    while(getline(cin, line)) {
        map<char, int> m;
        
        best = -1;

        fori(i, line.size()) {
            if(isalpha(line[i])) {
                m[line[i]]++;
                if(m[line[i]] > best) best = m[line[i]];
            }
        }

        res = "";

        for(auto iter = m.begin(); iter != m.end(); ++iter) {
            if(iter->second == best) res += iter->first;
        }

        sort(all(res));

        cout << res << " " << best << endl;
    }

    return 0;
}
