
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

    int k;
    cin >> k;

    int months[12] = {};

    fori(i, 12) cin >> months[i];

    sort(months, months + 12);

    int total = 0;
    int m = 0;
    int i = 11;

    while(total < k && i >= 0) {
        total += months[i];
        --i;
        ++m;
    }

    if(total >= k) cout << m << endl;
    else cout << -1 << endl;

    return 0;
}
