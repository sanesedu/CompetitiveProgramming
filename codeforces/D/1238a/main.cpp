
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

    long long res = 0; //number of bad strings
    int prev = 0;

    fori(i, s.size()) {
        if(i == 0 || s[i] != s[i - 1]) { //different symbol found
            res += i - prev;
            prev = i;
        } else {
            if(prev) ++res;
        }
    }

    long long val = (long long) n * (long long) (n + 1) / 2;
    cout << val - res - n << endl;

    return 0;
}
