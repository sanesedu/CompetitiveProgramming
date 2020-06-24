
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int solve(string s) {
    
    int res = 0;
    int mult = 1;
    
    int len = s.length();

    fori(i, len) {
        res += mult * (s[i] - '0');
        mult *= -1;
    }
    
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string line, s;

    int len;

    while(getline(cin, line)) {
        if(line == "0") break;

        len = line.length();

        s = "";

        fori(i, len) {
            if(isdigit(line[i])) s += line[i];
        }

        int equiv = solve(s);
    
        if(equiv % 11 == 0) cout << s << " is a multiple of 11." << endl;
        else cout << s << " is not a multiple of 11." << endl;
    }

    return 0;
}
