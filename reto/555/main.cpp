
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
typedef pair<int, int> pi;

    
int c, r,cols, rows, v;

void paint(vector<vector<int>> &mat, int c, int r) {
    
    --c;
    --r;

    mat[r][c] = -1;

    int start = max(0, c - 10);

    int end = min(cols, c + 10);

    for(int i = start; i < end; ++i) {
        mat[r][i] = -1;
    }

    start = max(0, r-10);
    end = min(rows, r+10);

    for(int i = start; i < end; ++i) {
        mat[i][c] = -1;
    } 
}

void print(vector<vector<int>> mat) {
    
    fori(i, rows) {
        fori(j, cols) {
            cout << mat[i][j] << "  ";   
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

    while(cin >> cols) {
        if(cols == 0) break;

        cin >> rows >> v;
    
        vector<int> arr(v);

        vector<vector<int>> mat(cols, vector<int>(rows, 0));
        
        fori(i, v) {
            print(mat);
            cin >> c >> r; 
            paint(mat, c, r);
        }
            print(mat);
    
    }

    return 0;
}
