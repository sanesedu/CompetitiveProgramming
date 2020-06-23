
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 0x3F3F3F3F

using namespace std;

void print(vector<vector<long long>> memo, int f, int c) {
    fori(i, f) {
        fori(j, c) {
            cout << memo[i][j] << " ";
        } 
        cout << endl;
    }
}

int main() {

    int c, f;

    while(cin >> c >> f) {

        vector<vector<long long>> mat(f, vector<long long>(c));
        
        fori(i, f) {
            fori(j, c) { 
                cin >> mat[i][j];
            }
        }
        
        for(int r = f - 1; r >= 0; --r) {
            for(int p = c - 1; p >= 0; --p) {
                if(r == f-1 && p == c-1) {
                    mat[r][p] = 2;
                } else if(r == f-1) {
                    mat[r][p] = mat[r][p+1] - mat[r][p];
                } else if(p == c-1) {
                    mat[r][p] = mat[r+1][p] - mat[r][p];
                } else {
                    mat[r][p] = min(mat[r+1][p], mat[r][p+1]) - mat[r][p];
                } 
                if(mat[r][p] < 2) mat[r][p] = 2;
            }
        }

//        print(mat, f, c);

        cout << mat[0][0] << endl;
    }
    
    return 0;
}
