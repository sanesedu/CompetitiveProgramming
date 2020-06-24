
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

    string a, b;

    int la, lb;

    while(getline(cin, a) && getline(cin, b)) {
         la = a.length();
         lb = b.length();

         vector<vector<int>> dp(la+1, vector<int>(lb+1, 0));
    
         for(int i = 1; i <= la; ++i) {
            for(int j = 1; j <= lb; ++j) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];                    
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
         }
         
         cout << dp[la][lb] << endl;
    }

    return 0;
}
