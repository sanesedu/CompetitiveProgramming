
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

    string line;

    long long res;

    long long len;

    while(getline(cin, line)) {
        if(line == "0") break;
        
        len = line.length();

        reverse(all(line));

        res = 0;

        fori(i, len) {
            res += (line[i] - '0') * ((1 << (i+1)) - 1);
        }
        
        cout << res << endl;
    }

    return 0;
}
