
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

    int derangement[13];
    int factorial[13];
    
    derangement[0] = 1;
    derangement[1] = 0;

    factorial[0] = factorial[1] = 1;

    for(int i = 2; i <= 12; ++i) {
        derangement[i] = (i - 1) * (derangement[i-1] + derangement[i-2]);
        factorial[i] = i * factorial[i-1]; 
    }
    
    int q, n;
    cin >> q;

    while(q--) {
        cin >> n;
        cout << derangement[n] << "/" << factorial[n] << endl;
    }

    return 0;
}
