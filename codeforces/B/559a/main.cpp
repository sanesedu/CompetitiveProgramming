
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

string min_lex(string s) {
    if(s.length() % 2) return s;
    string s1 = min_lex(s.substr(0, s.length()/2));
    string s2 = min_lex(s.substr(s.length()/2, s.length()));
    if(s1 < s2) return s1 + s2;
    else return s2 + s1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string a, b;
    cin >> a >> b;

    if(min_lex(a) == min_lex(b)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
