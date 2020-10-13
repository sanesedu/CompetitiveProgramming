
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 500010

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    vector<int> res(N);

    int cur = 1;
    int end = 1;

    fori(i, N) {
        res[i] = cur;

        if(cur == end) {
            cur = 2;
            end *= 2;
        } else {
            cur += 2;
        }
    }
    
    int n;

    while(cin >> n, n) {
        cout << res[n-1] << endl; 
    }

    return 0;
}
