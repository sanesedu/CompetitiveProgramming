
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

    int n, tmp;

    while(cin >> n) {

        if(n == 0) break;

        vector<int> col(n, 0); 
        vector<int> row(n, 0); 

        fori(i, n) {
            fori(j, n) {
                cin >> tmp;
                row[i] ^= tmp;
                col[j] ^= tmp;
            }
        }
        
        int c = -1;
        int cc = 0;
        int r = -1;
        int rr = 0;

        fori(i, n) {
            if(col[i] == 1) {
                c = i;
                ++cc;
            } 
            if(row[i] == 1) {
                r = i;
                ++rr;
            }
        }
        
        if(rr == 0 && cc == 0) cout << "OK\n";
        else if(rr == 1 && cc == 1) cout << "Change bit (" << r+1 << "," << c+1 << ")\n"; 
        else cout << "Corrupt" << endl;
    }

    return 0;
}
