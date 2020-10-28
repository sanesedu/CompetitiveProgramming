
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

int main() {

    int t, n, inc, dec, resi, resd;
    cin >> t;

    fori(i, t) {

        cin >> n;

        int height[n], width[n], lis[n], lds[n];
       
        fori(j, n) cin >> height[j];
        fori(j, n) cin >> width[j];

        resi = resd = inc = dec = 0;

        fori(j, n) {
            inc = dec = 0;
            for(int k = 0; k < j; ++k) {
                if(height[k] < height[j]) {
                    inc = max(inc, lis[k]); 
                } else if(height[k] > height[j]) {
                    dec = max(dec, lds[k]); 
                }
            }
            lis[j] = width[j] + inc;
            resi = max(resi, lis[j]);
            
            lds[j] = width[j] + dec;
            resd = max(resd, lds[j]);
        }

        if(resi >= resd) printf("Case %d. Increasing (%d). Decreasing (%d).\n", i+1, resi, resd);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n", i+1, resd, resi);
    }

    return 0;
}
