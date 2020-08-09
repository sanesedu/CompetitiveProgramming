
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 1000005

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int memo[N];

    int mid, res, n;
    
    memo[1] = memo[2] = 1;
    memo[3] = memo[4] = 2;

    for(int i = 5; i < N; ++i) {
        mid = (i+1)/2;
        if(i % 2 == 0) {
            memo[i] = memo[mid] + memo[mid+1] - 1;
        } else {
            memo[i] = 2 * memo[mid] - 1;
        }
    }

    while(cin >> n) {
        
        if(n == 0) break;
        
        cout << memo[n] << endl;
    }

    return 0;
}