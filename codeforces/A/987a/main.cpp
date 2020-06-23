
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
    
    map<string, string> m;
    m.insert(make_pair("purple", "Power"));
    m.insert(make_pair("green", "Time"));
    m.insert(make_pair("blue", "Space"));
    m.insert(make_pair("orange", "Soul"));
    m.insert(make_pair("red", "Reality"));
    m.insert(make_pair("yellow", "Mind"));

    set<string> colors = {"purple", "green", "blue", "orange", "red", "yellow"};

    set<string> found, res;

    int n;
    cin >> n; 
    
    string s;

    fori(i, n) {
        cin >> s;
        found.insert(s);
    }

    set_difference(colors.begin(), colors.end(), found.begin(), found.end(), inserter(res, res.end()));

    cout << res.size() << endl;

    set<string>::iterator it;

    for(it = res.begin(); it != res.end(); ++it) {
        cout << m[*it] << endl; 
    }

    return 0;
}
