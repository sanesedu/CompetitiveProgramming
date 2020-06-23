
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
    
    int n, l, r;
    cin >> n >> l >> r;

    int min = n - l + 1;
    int m = n - min;

    int p = 2;

    while(m > 0) {
        min += p;
        --m;
        p *= 2; 
    }

    int max = 0;

    for(int i = 0; i < r; ++i) {
        max += pow(2, i);
    }

    if(r < n) {
        max += (n-r) * pow(2, r-1);
    }

    cout << min << " " << max << endl;

    return 0;
}
