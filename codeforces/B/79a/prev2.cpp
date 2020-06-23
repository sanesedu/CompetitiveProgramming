
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

    vector<int> v(n*m, 0);

    fori(i, k) {
        cin >> a >> b;
        v[(a-1)*m + (b-1)] = -1;
    }

    int prev = -1;

    fori(i, m*n) {
        if(v[i] == -1) continue;
        else v[i] = ++prev;
    }

    vector<string> crop = {"Carrots", "Kiwis", "Grapes"};

    fori(i, t) {
        cin >> a >> b;
        int temp = v[(a-1)*m + (b-1)];
        if(temp == -1) cout << "Waste" << endl;
        else cout << crop[temp % 3] << endl;
    }

    return 0;
}
