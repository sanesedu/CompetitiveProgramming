
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
    
    int n;

    while(cin >> n) {
        vector<long long> ver(n);
        vector<long long> hor(n);

        fori(i, n) cin >> ver[i];
        fori(i, n) cin >> hor[i];

        long long res[3] = {0};

        forb(i, 1, n) {
            forb(j, 1, n) {
                res[(i + j) % 3] += (ver[i-1] * hor[j-1]);
            }
        }

        cout << res[0] << " " << res[1] << " " << res[2] << endl;

    }

    return 0;
}
