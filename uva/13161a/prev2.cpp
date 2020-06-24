
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

    set<int> s;

    int prev = 3;
    int val = 4;
    int temp = 0;

    while(prev < 1000) {
        s.insert(prev);
        cout << prev << " ";
        temp = prev;
        prev = val;
        val = temp + prev;
    }

    cout << endl;

    int d, r, t, res;

    set<int>::iterator it, jit;

    while(cin >> d >> r >> t) {

        it = s.lower_bound(r);
        jit = s.lower_bound(t);

        while(it != s.begin() && jit != s.end()) {
            temp = (*it - 3 - *jit) / d;
            if((*it - 3 - *jit) % d == 0) {
                res = temp;
               break; 
            }
            --it;
            ++jit;
        }

        cout << res << endl;
    }

    return 0;
}
