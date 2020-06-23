
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

long long solve(vector<long long> arr, long long n, long long goal) {

    long long count[goal + 1];
    
    memset(count, 0, sizeof(count));

    count[0] = 1;

    for (long long i = 1; i <= goal; i++) {
        for (long long j = 0; j < n; j++) {
            if (i >= arr[j]) {
                count[i] += (count[i - arr[j]] % MOD);
                count[i] = count[i] % MOD;
            }
        }
    }
    
    return count[goal] % MOD;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long goal, n;

    while(cin >> goal) {
        
        if(goal == 0) break;

        cin >> n;

        vector<long long> arr(n);

        fori(i, n) cin >> arr[i];
        
        cout << solve(arr, n, goal) << endl;
    }

    return 0;
}
