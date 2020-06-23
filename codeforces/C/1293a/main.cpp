
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

    int tmp, a, b, n, q;
    cin >> n >> q;

    vector<vector<bool>> mat(2, vector<bool>(n, false));

    int blockedPair = 0;

    fori(i, q) {
        cin >> a >> b;
        --a;
        --b;
        
        tmp = (mat[a][b]) ? 1 : -1;
        
        mat[a][b] = !mat[a][b];

        for(int dy = -1; dy <= 1; ++dy) {
            if(b + dy < 0 || b + dy >= n) continue;

            if(mat[1 - a][b + dy]) blockedPair += tmp;
        }

        if(blockedPair) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}
