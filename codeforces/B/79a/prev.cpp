
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

    int n, m, k, t, a, b;
    cin >> n >> m >> k >> t;

    vector<vector<string>> field(n+1, vector<string>(m+1)); 

    fori(i, k) {
        cin >> a >> b;
        field[a][b] = "Waste";
    }

    vector<string> crop = {"Carrots", "Kiwis", "Grapes"};

    int c = 0;

    fori(i, n) {
        fori(j, m) {
            if(field[i+1][j+1] != "Waste") {
                field[i+1][j+1] = crop[c%3];
                ++c;
            }
        }
    }

    fori(i, t) {
        cin >> a >> b;
        cout << field[a][b] << endl;
    }

    return 0;
}
