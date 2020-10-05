
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

    map<string, vector<string>> dict;

    string tmp, otmp;

    while(cin >> tmp) {
        if(tmp == "#") break;

        otmp = tmp;
        
        transform(otmp.begin(), otmp.end(), otmp.begin(), ::tolower);
        sort(all(otmp));
       
        dict[otmp].pb(tmp);
    }

    vector<string> res;

    for(auto iter = dict.begin(); iter != dict.end(); ++iter) {
        if(iter->second.size() == 1) {
            res.pb(iter->second[0]); 
        }
    }

    sort(all(res));

    for(int i = 0; i < (int) res.size(); ++i) {
        cout << res[i] << endl;
    }

    return 0;
}
