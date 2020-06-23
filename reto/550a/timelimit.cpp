
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int solve(int l, int r) {
    
    int mid = l + (r-l)/2;

    int res = 0;

    if((mid - l) > 1 && (r - mid) > 1) {
        res = 1 + solve(l, mid) + solve(mid, r);
    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int res, n;

    bool turn;

    while(cin >> n) {
        
        if(n == 0) break;

        if(n <= 2) {
            cout << 1 << endl; 
        } else {
            res = solve(0, n-1);
            cout << res + 2 << endl;
        }
    }

    return 0;
}
