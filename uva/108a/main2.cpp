
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int n;

int mat[110][110];

int maxSum(int n) {

    int temp[n];

    int res = -128 * 100 * 100;

    int curmax;

    for(int left = 0; left < n; ++left) {
    
        memset(temp, 0, sizeof(temp));

        for(int right = left; right < n; ++right) {
        
            for(int i = 0; i < n; ++i) {
                temp[i] += mat[i][right];
            }

            //Kadane's algorithm

            curmax = 0;

            for(int j = 0; j < n; ++j) {
                curmax += temp[j];
                res = max(res, curmax);                
                if(curmax < 0) curmax = 0;
            }
        }
    }
    
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    while(cin >> n) {
        
        fori(i, n) {
            fori(j, n) {
                cin >> mat[i][j];
            }
        }

        int res = maxSum(n);

        cout << res << endl;

    }

    return 0;
}
