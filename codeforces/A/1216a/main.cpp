
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

    int n;
    string s;

    cin >> n >> s;

    int as = 0;
    int bs = 0;

    int res = 0;

    for(int i = 0; i < n; ++i) {
        if(s[i] == 'a') ++as;
        else ++bs;

        if(i % 2) {
            if(as == bs) continue;
            else if(as > bs) {
                if(s[i] == 'a') {
                    s[i] = 'b';
                } else {
                    s[i - 1] = 'b';
                }
                ++bs;
                --as;
            } else {
                if(s[i] == 'b') {
                    s[i] = 'a';
                } else {
                    s[i - 1] = 'a';
                }
                ++as;
                --bs;
            }
            ++res;
        } 
    }
    
    cout << res << endl << s << endl;

    return 0;
}
