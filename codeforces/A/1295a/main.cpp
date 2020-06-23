
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
    
    map<int, int> m;
    m[0] = 6;
    m[1] = 2;
    m[2] = 5;
    m[3] = 5;
    m[4] = 4;
    m[5] = 5;
    m[6] = 6;
    m[7] = 3;
    m[8] = 7;
    m[9] = 6;

    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        string s = "";
        while(n > 0) {
            if(n == 3) {
                s.append("7");
                n -= 3;
            } else {
                s.append("1");
                n -= 2;
            } 
        }
        reverse(all(s));
        cout << s << endl;
    }

    return 0;
}
