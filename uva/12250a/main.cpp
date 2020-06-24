
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

    map<string, string> mp;
    mp["HELLO"] = "ENGLISH";
    mp["HOLA"] = "SPANISH";
    mp["HALLO"] = "GERMAN";
    mp["BONJOUR"] = "FRENCH";
    mp["CIAO"] = "ITALIAN";
    mp["ZDRAVSTVUJTE"] = "RUSSIAN";

    string line;

    int index = 0;

    while(getline(cin, line)) {
        if(line == "#") break;
        if(mp.count(line)) cout << "Case " << ++index << ": " << mp[line] << endl;
        else cout << "Case " << ++index << ": UNKNOWN" << endl;
    }

    return 0;
}
