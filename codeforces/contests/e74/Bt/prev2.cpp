
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

    int q, n, r, t;
    cin >> q;

    while(q--) {
        cin >> n >> r;

        set<int> arr;

        fori(i, n) {
            cin >> t;
            arr.insert(t);
        }

        int res = 0;
        
        while(arr.size() > 0) {

            set<int>::iterator it = arr.end();
            
            arr.erase(it);

            for(it = arr.begin(); it != arr.end(); ++it) {
                if(*it <= r) {
                    arr.erase(it);
                } else {
                    int temp = *it;
                    arr.erase(it);
                    arr.insert(temp - r);
                }
            }

            ++res;
        }

        cout << res << endl;
    }

    return 0;
}
