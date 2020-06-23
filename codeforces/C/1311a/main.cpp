
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

    int t, n, m, p;
    string s;
    
    cin >> t;

    while(t--) {
    
        cin >> n >> m >> s;
        vector<int> res(26, 0);
        vector<int> freq(n, 0);

        fori(i, m) {
            cin >> p;
            ++freq[p-1];
        }

        for(int i = n-1; i > 0; --i) {
            freq[i-1] += freq[i];
        }

        fori(i, n) {
            res[s[i] - 'a'] += freq[i];
            ++res[s[i] - 'a'];
        }
        
        fori(i, 26) {
            cout << res[i] << " ";
        }
        cout << endl;

    }

    return 0;
}
