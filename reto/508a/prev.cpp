
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
    
    long long n, x, y;

    while(cin >> n) {
        if(n == 0) break;

        vector<pair<long long, long long>> arr;

        long long sum = 0;    

        fori(i, n) {
            cin >> x >> y;
            arr.pb(make_pair(x, y));
            sum += x;
        }
        
        long long px = sum / n;
        
        long long res = 0;

        vector<pair<long long, long long>>::iterator it;

        for(it = arr.begin(); it != arr.end(); ++it) {
            if(it->second >= abs(it->first - px)) ++res;
        } 
        
        cout << res << endl;

    }

    return 0;
}
