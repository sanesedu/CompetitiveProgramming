
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

    int denoms[5] = {100, 20, 10, 5, 1};

    int total = (n/denoms[0]);
    int left = n - (n/denoms[0])*denoms[0];

    forb(i, 1, 4) {
        total += (left/denoms[i]);
        left -= (left/denoms[i])*denoms[i];
    }

    cout << total << endl;

    return 0;
}
