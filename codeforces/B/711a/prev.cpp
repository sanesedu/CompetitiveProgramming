
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

    long long sum = 0;
    long long tsum;
    int pos[2] = {}; 
    
    long long arr[n][n] = {};

    fori(i, n) {
        tsum = 0;
        fori(j, n) {
            cin >> arr[i][j];
            if(arr[i][j] == 0) pos[0] = i, pos[1] = j;
            tsum += arr[i][j];
        }

        if(tsum > sum) sum = tsum;
    }

    long long vsum = 0;
    long long hsum = 0;

    fori(i, n) {
        vsum += arr[i][pos[1]];
        hsum += arr[pos[0]][i];
    }

    long long md = 0;
    long long ld = 0;

    if(pos[0] == pos[1]) {
        fori(i, n) {
            md += arr[i][i];
        }
    } else {
        md = vsum;
    }

    if(pos[0] + pos[1] == n-1) {
        fori(i, n) {
            ld += arr[i][n-1-i];
        }
    } else {
        ld = vsum;
    }
    
    if(n == 1) cout << "1\n";
    else if(vsum != hsum || ld != md || vsum != ld || vsum != md) cout << "-1\n";
    else if (sum - vsum <= 0) cout << "-1\n";
    else cout << sum - vsum << "\n";

    return 0;
}
