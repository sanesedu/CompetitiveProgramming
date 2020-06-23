
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

    vector<int> p(n), deg(n);

    forb(i, 1, n-1) {
        cin >> p[i];
        --p[i];
        ++deg[p[i]];
    }

    vector<int> leaves(n);

    fori(i, n) {
        if(deg[i] == 0) {
            ++leaves[p[i]];
        }
    }

    fori(i, n) {
        if(deg[i] > 0 && leaves[i] < 3) {
            cout << "No\n";
            return 0;
        }
    }
    
    cout << "Yes\n";

    return 0;
}
