
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int row[8];

int a, b, solnum;

bool safe(int r, int c) {
    for(int i = 0; i < c; ++i) { //all previous columns, already placed queens
        if(row[i] == r || (abs(row[i] - r) == abs(i - c))) {
            //same row or same diagonal
            return false;
        }
    }
    return true;
}

void backtrack(int c) {
    
    if(c == 8 && row[b] == a) { //all queens placed and first one in correct square
        printf("%2d      ", ++solnum);
        for(int i = 0; i < 8; ++i) {
            if(i) cout << " ";
            cout << row[i] + 1;
        }
        cout << endl;
    }

    for(int r = 0; r < 8; ++r) {
        if(safe(r, c)) {
            row[c] = r;
            backtrack(c+1);
        }
    }

}

int main() {

    int q;
    cin >> q;

    while(q--) {
        cin >> a >> b;
        --a;
        --b;
        solnum = 0;
        memset(row, 0, sizeof(row));
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if(q) cout << endl;
    }

    return 0;
}
