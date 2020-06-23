
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

    string s;
    cin >> s;

    int total = 0;

    for(int i = 0; i < s.length(); ++i) {
        if(i == 0) total += min(('a' - s[i] + 26) % 26, (s[i] - 'a' + 26) % 26); 
        else total += min((s[i]-s[i-1] + 26) % 26, (s[i-1] - s[i] + 26) % 26);
    }

    cout << total << endl;

    return 0;
}
