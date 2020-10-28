
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
typedef pair<int, int> ii;

int table[92][8] = {};
int row[8] = {};
bool md[20] = {};
bool sd[20] = {};
bool rw[20] = {};

int idx;

void place(int c) {
    if(c == 8) {
        memcpy(table[idx], row, sizeof(row));
        idx++;
        return;
    } else {
        fori(r, 8) {
            if(!rw[r] && !md[r - c + 7] && !sd[r + c]) {
                row[c] = r;
                rw[r] = md[r - c + 7] = sd[r + c] = true;
                place(c+1);
                rw[r] = md[r - c + 7] = sd[r + c] = false;
            }
        }
    }
}

void preproc() {
    idx = 0;
    memset(row, 0, sizeof(row));
    place(0);
}

int solve() {
    int res = 8;
    int cur;

    fori(i, 92) {
        cur = 0;
        fori(j, 8) {
            if(row[j] != table[i][j]) ++cur;
        }
        res = min(res, cur);
        if(res == 0) break;
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    preproc();

    string line;

    int i = 0;

    while(getline(cin, line)) {
        
        stringstream ss(line);

        fori(i, 8) {
            ss >> row[i];
            row[i]--;
        }

        cout << "Case " << ++i << ": " << solve() << endl;
    }

    return 0;
}
