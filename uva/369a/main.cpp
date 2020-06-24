
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


    vector<vector<long long>> pascal(101, vector<long long>(101, 0));

    pascal[1][1] = 1;
    pascal[1][0] = 1;

    for(int i = 2; i <= 100; ++i) {
        pascal[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
    }

    long long n, m;

    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        cout << n << " things taken " << m << " at a time is " << pascal[n][m] << " exactly." << endl;
    }

    return 0;
}
