
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(long long i = 0; i < (int)(n); ++i)
#define forid(i, n) for(long long i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(long long i = (int)(a); i <= (int)(b); ++i)

using namespace std;

vector<pair<long long, long long>> res;

long long zero(long long n, long long m, vector<vector<long long>> a, long long sum) {

    long long opers = 0;

    for(long long i = 0; i < n-1; ++i) {
        for(long long j = 0; j < m-1; ++j) {
            if(a[i][j] != INT_MIN && a[i+1][j] != INT_MIN && a[i][j+1] != INT_MIN && a[i+1][j+1] != INT_MIN) { //can be overwriten
                if(a[i][j] == 1 || a[i+1][j] == 1 || a[i][j+1] == 1 || a[i+1][j+1] == 1) { //needs to be overwritten

                    if(a[i][j] == 1) --sum;
                    if(a[i+1][j] == 1) --sum;
                    if(a[i][j+1] == 1) --sum;
                    if(a[i+1][j+1] == 1) --sum;

                    --a[i][j];
                    --a[i+1][j];
                    --a[i][j+1];
                    --a[i+1][j+1];

                    ++opers;
                    res.pb(make_pair(i+1, j+1));
                }
            }
        }
    }

    if(sum == 0) return opers;
    else return -1;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    long long n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n+10, vector<long long>(m+10));

    long long sum = 0;

    fori(i, n) {
        fori(j, m) {
            cin >> a[i][j];
            sum += a[i][j];
            if(a[i][j] == 0) a[i][j] = INT_MIN;
        }
    }

    long long r = zero(n, m, a, sum);

    if(r == -1) {
        cout << "-1\n";
    } else {
        cout << r << "\n";

        vector<pair<long long, long long>>::iterator it;

        for(it = res.begin(); it != res.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
    }

    return 0;
}
