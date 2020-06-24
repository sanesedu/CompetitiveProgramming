
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int mat[35][35];

int maxsum(int m, int n) {
    
    int temp[m];

    int res = -10000000;

    int cur;

    for(int left = 0; left < n; ++left) {
        memset(temp, 0, sizeof(temp));
        for(int right = left; right < n; ++right) {
            
            fori(i, m) {
                temp[i] += mat[i][right];
            }

            cur = 0;

            fori(i, m) {
                cur += temp[i];
                res = max(res, cur);
                if(cur < 0) cur = 0;
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
    
    int q, i, j;
    cin >> q;

    string s;

    getline(cin, s);
    getline(cin, s);

    while(q--) {
        i = 0;
        j = 0;
        
        while(getline(cin, s)) {
            
            if(s.empty()) break;
            
            j = s.length();

            for(int k = 0; k < (int) s.length(); ++k) {
                if(s[k] == '0') mat[i][k] = -10000000;
                else mat[i][k] = 1; 
            }
            ++i;
        }
        
        int res = maxsum(i, j);

        cout << max(0, res) << endl;
        if(q) cout << endl;
    }

    return 0;
}
