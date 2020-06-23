
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int solve(vector<vector<int>> &mat, int n) {
    
    for(int i = 0; i < n; ++i) {
        for(int j = n-1; j >= 0; --j) {
            if(mat[i][j] >= 0) continue;
            if(i == 0) mat[i][j] = mat[i][j+1]; 
            if(j == n-1) mat[i][j] = mat[i-1][j]; 
            if(i > 0 && j < n-1) mat[i][j] = mat[i][j+1] + mat[i-1][j];
        }
    }
    
    return mat[n-1][0];
}

void print(vector<vector<int>> mat, int n) {
    
    fori(i, n) {
        fori(j, n) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n;

    while(cin >> n) {
        if(n == 0) break;
        
        vector<vector<int>> mat(n, vector<int>(n, -1));
        
        char c;

        fori(i, n) {
            fori(j, n) {
                cin >> c;
                if(c == 'X') mat[i][j] = 0;
            }
        }

        mat[0][n-1] = 1;
        
        int res = solve(mat, n);
        
        cout << res << endl; 
    }

    return 0;
}
