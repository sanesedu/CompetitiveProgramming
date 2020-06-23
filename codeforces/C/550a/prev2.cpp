
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

long long div(string s, long long n) {
    
    long long m = (1 << n)  - 1;

    long long t = 0;

    while(m > 0) {
        
        t = 0;    
        long long mult = 1;

        for(long long i = s.length()-1; i>= 0; --i) {
            if(m & (1 << i)) {
                t += (s[i] - '0') * mult;
                mult *= 10;
            }
        }    
        
        if(t % 8 == 0) return t;

        --m;
    }

    if(t % 8 == 0) return t;

    return -1;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    string s;
    cin >> s;

    long long res = div(s, s.length());

    if(res != -1) cout << "YES\n" << res << endl;
    else cout << "NO\n";

    return 0;
}
