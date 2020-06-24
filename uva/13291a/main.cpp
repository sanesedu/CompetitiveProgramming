
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
    
    long long n, v, h;

    while(cin >> n) {
        vector<long long> ver(3, 0);
        vector<long long> hor(3, 0);

        forb(i, 1, n) {
            cin >> v;
            ver[i % 3] += v;
        }

        forb(i, 1, n) {
            cin >> h;
            hor[i % 3] += h;
        }

        long long res[3] = {0};

        fori(i, 3) {
            fori(j, 3) {
                res[(i + j) % 3] += (ver[i] * hor[j]);
            }
        }

        cout << res[0] << " " << res[1] << " " << res[2] << endl;

    }

    return 0;
}
