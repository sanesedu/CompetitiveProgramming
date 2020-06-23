
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
    cin >> n;

    string s;
    cin >> s;

    int zeros = 0;
    int ones = 0;

    fori(i, n) {
        if(s[i] == '0') ++zeros;
        else ++ones;
    }

    while(ones > 0 && zeros > 0) {
        fori(i, s.length()-1) {
            if((int)s[i] ^ (int)s[i+1] == 1) {
                --ones;
                --zeros;
                s.erase(i, 2);
                break;
            }
        }
    }

    cout << s.length() << endl;

    return 0;
}
