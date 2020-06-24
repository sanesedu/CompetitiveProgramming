
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

char mat[100][100];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void colour(int x, int y) {
    
    if((mat[x][y] != ' ') && (mat[x][y] != '_') && (mat[x][y] != '*')) {
        return;
    }

    mat[x][y] = '#';

    fori(i, 4) {
        colour(x + dx[i], y + dy[i]);
    }
    
    return;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int q;
    cin >> q;

    string line;
    getline(cin, line);

    while(q--) {
        
        int n = 0;

        while(cin.getline(mat[n], 100)) {
            if(mat[n][0] == '_') break;            
            ++n;
        }

        fori(i, n) {
            for(int j = 0; mat[i][j]; ++j) {
                if(mat[i][j] == '*') {
                    colour(i, j);
                }
            }
        }

        fori(i, n+1) {
            cout << mat[i] << endl;
        } 
    }

    return 0;
}
