
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

void print(char a[], int n) {

    fori(i, n) cout << a[i];
    cout << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n;
    cin >> n;

    string s, res;
    cin >> s;

    fori(i, n) {
        if(i % 2 == 0) {
            res += s[i];
        } else {
            res = s[i] + res;
        }
    }

    if(n % 2 == 0) reverse(all(res));

    cout << res << endl;

    return 0;
}
