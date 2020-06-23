
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

    long long n, w, t;

    while(cin >> n >> w) {
   
        map<long long, long long> m;

        long long maxlh = 0;

        fori(i, n) {
            cin >> t;
            if(t <= w/2) {
                maxlh = max(maxlh, t);
                m[w/2]++;
            } else if(t + maxlh <= w) {
                m[t]++;
            }
        }

        if(maxlh == 0 && m.size() > 0) cout << "1\n";
        else if(maxlh == 0) cout << "0\n";
        else {
            long long res = 0;
            
            map<long long, long long>::iterator it;

            for(it = m.begin(); it != m.end(); ++it) {
                if(it->first + maxlh <= w && (it->first + it->first) <= w) {
                    res += it->second;
                } else if(it->first + maxlh <= w && (it->first + it->first) > w) {
                    res++;
                    maxlh = it->first;
                }
            } 

            cout << res << endl;
        }
    }

    return 0;
}
