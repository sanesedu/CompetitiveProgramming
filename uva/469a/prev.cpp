
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

char mat[110][110];

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int ff(int row, int col, int a, int b) {
    
    if(a < 0 || a >= row || b < 0 || b >= col) return 0;

    if(mat[a][b] != 'W') return 0;

    mat[a][b] = '.';

    int res = 1;

    fori(i, 8) {
        res += ff(row, col, a + dx[i], b + dy[i]);
    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, a, b;
    cin >> q;

    string s;

    while(q--) {
        getline(cin, s);
        getline(cin, s);
    
        int row = 0;
        int col = 0;

        while(true) {
            getline(cin, s);
            if(isdigit(s[0])) break;
            strcpy(mat[row++], s.c_str());
            col = s.length();
        }

        while(!s.empty()) {
            stringstream ss(s);
            ss >> a >> b;
            --a;
            --b;
            cout << ff(row, col, a, b) << endl;
            getline(cin, s);
        }
        
        cout << endl;
    }

    return 0;
}
