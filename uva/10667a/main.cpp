
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int maxsum(vector<vector<int>> mat, int s) {

    int temp[s];

    int res = -10000000;

    int cur;

    for(int left = 0; left < s; ++left) {
        
        memset(temp, 0, sizeof(temp));
        
        for(int right = left; right < s; ++right) {

            fori(i, s) {
                temp[i] += mat[i][right];
            }

            //Kadane's algorithm
            
            cur = 0;

            fori(i, s) {
                cur += temp[i];
                res = max(res, cur);
                if(cur < 0) cur = 0;
            }
        }
    }

    return res;
}

int maxsum2(vector<vector<int>> mat, int s) {

    //cumulative sum matrix
    
    fori(i, s) {
        fori(j, s) {
            if(i > 0) mat[i][j] += mat[i-1][j];
            if(j > 0) mat[i][j] += mat[i][j-1];
            if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
        }
    }

    //answer
    
    int res = -100000000;

    int temp;

    for(int i = 0; i < s; ++i) {
        for(int j = 0; j < s; ++j) {
            for(int k = i; k < s; ++k) {
                for(int l = j; l < s; ++l) {
                    temp = mat[k][l];
                    
                    if(i > 0) temp -= mat[i-1][l];
                    if(j > 0) temp -= mat[k][j-1];
                    if(i > 0 && j > 0) temp += mat[i-1][j-1];
                    
                    res = max(res, temp);
                }
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
    
    int p, s, t, a, b, c, d;
    cin >> p;

    while(p--) {
        cin >> s >> t;
        
        vector<vector<int>> mat(s, vector<int>(s, 1));

        fori(i, t) {
            cin >> a >> b >> c >> d;
            a--; b--; c--; d--;
            forb(j, a, c) {
                forb(k, b, d) {
                    mat[j][k] = -10000000;
                }
            }
        }

        int res = maxsum(mat, s);

        cout << max(0, res) << endl;

    }

    return 0;
}
