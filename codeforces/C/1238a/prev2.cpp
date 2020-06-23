
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

    int q, h, n;
    cin >> q;

    while(q--) {
        cin >> h >> n;

        int arr[n] = {};
        
        fori(i, n) cin >> arr[i];

        int res = 0;
        int pos = 0;

        while(pos < n) {
        
            if(pos + 1 < n && arr[pos+1] == arr[pos] - 1) {
                
                if(pos + 2 < n && arr[pos+2] == arr[pos] - 2) {
                    pos += 2;
                } else {
                    cout << "here " << pos << endl;
                    ++res;
                    pos += 2;
                }

            } else {
                ++pos;
            }
        }

        cout << res << endl;

    }

    return 0;
}
