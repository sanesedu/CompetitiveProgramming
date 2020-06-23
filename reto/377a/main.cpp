
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

    int n;

    while(getline(cin, s)) {
        
        n = 0;
        
        fori(i, s.length()) {
            n = (n * 10) + (s[i] - '0');
            n %= 16; 
        }
        
        if((n&0xf) == 0 || (n&0xf) == 1 || (n&0xf) == 4 || (n&0xf) == 9) {
            cout << "NO SE\n"; 
        } else {
            cout << "IMPERFECTO\n";
        }
    }

    return 0;
}
