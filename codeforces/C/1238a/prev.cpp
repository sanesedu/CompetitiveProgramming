
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

    int q, h, n, t;
    cin >> q;

    while(q--) {
        cin >> h >> n;

        int arr[h+1] = {0};
        
        fori(i, n) {
            cin >> t;
            arr[t] = 1;
        } 

        arr[0] = 1;

        int res = 0;
        int pos = h;

        while(pos > 1) {
            
            arr[pos-1] = abs(arr[pos-1] - 1);
            
            if(arr[pos-1] == 1) --pos;
            else if(arr[pos-2] == 1) {
                pos -= 2;
            } else {
                ++res;
                pos -= 2;
            }
        }

        cout << res << endl;

    }

    return 0;
}
