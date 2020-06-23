
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
    
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if(k >= 1 && n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int i = 0;

    while(k > 0 && i < n) {
       if(i == 0) {
           if(s[i] != '1') {
               s[i] = '1';
               --k;
           }
       } else {
           if(s[i] != '0') {
               s[i] = '0';
               --k;
           }
       }
       ++i;
    }

    cout << s << endl;

    return 0;
}
