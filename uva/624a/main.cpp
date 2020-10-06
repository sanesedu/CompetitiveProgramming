
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
typedef pair<int, int> ii;

int res, best;

void backtrack(int i, int n, vector<int> arr, int mask, int total) {

    if(total > n) return;

    if(total > best) {
        best = total;
        res = mask;
    }

    if(i >= (int) arr.size()) return;

     backtrack(i+1, n, arr, mask | (1 << i), total + arr[i]);
     backtrack(i+1, n, arr, mask, total);
}

void solve(int n, vector<int> arr) {
    backtrack(0, n, arr, 0, 0);

    for(int i = 0; i < (int) arr.size(); ++i) {
        if((res >> i) % 2) {
            cout << arr[i] << " ";
        }
    }

    cout << "sum:" << best << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, t;

    while(cin >> n >> t) {
        vector<int> arr(t);
    
        fori(i, t) cin >> arr[i];

        res = -1;
        best = -1;

        solve(n, arr);
    }

    return 0;
}
