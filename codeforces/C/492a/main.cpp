
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
    long long r, avg;
    cin >> n >> r >> avg;

    vector<pair<long long, long long>> v(n);

    long long total = 0;

    fori(i, n) {
        cin >> v[i].second >> v[i].first;
        total += v[i].second;
    }

    if(total/n >= avg) {
        cout << "0\n";
    } else {
        sort(all(v));
        
        long long goal = n * avg;

        long long res = 0;

        long long temp = 0;

        fori(i, n) {
            temp = min(goal - total, r - v[i].second) ;
            total += temp;
            res += temp * v[i].first;
            if(total >= goal) break;
        }

        cout << res << "\n";

    }

    return 0;
}
