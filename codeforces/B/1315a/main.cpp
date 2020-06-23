
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

    int i, sum, len, t, a, b, p;
    cin >> t;

    string s;

    while(t--) {
        cin >> a >> b >> p; 
        cin.ignore();

        getline(cin, s);
    
        sum = 0;

        len = s.length();

        for(i = len - 2; i >= 0; --i) {
            sum += ((s[i] == 'A') ? a : b);
            if(sum > p) break;
            while(i > 0 && s[i] == s[i-1]) --i; 
        }

        cout << i + 2 << endl;
    }

    return 0;
}
