
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
    
    map<string, int> m, f;

    int n;
    cin >> n;

    string names[n];
    int scores[n];

    fori(i, n) {
        cin >> names[i] >> scores[i];
        m[names[i]] += scores[i];
    }

    int maxScore = -1001;

    fori(i, n) {
        maxScore = max(maxScore, m[names[i]]);
    }

    fori(i, n) {
        f[names[i]] += scores[i];
        if(m[names[i]] == maxScore && f[names[i]] >= maxScore) {
            cout << names[i] << endl;
            break;
        }
    }

    return 0;
}
