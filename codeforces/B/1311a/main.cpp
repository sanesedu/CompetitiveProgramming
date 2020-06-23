
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

    int t, n, m, a;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        vector<int> arr(n);

        fori(i, n) cin >> arr[i];

        vector<bool> p(n, false);

        fori(i, m) {
            cin >> a;
            p[--a] = true;
        }

        bool flag = true;

        while(flag) {
            
            flag = false;

            fori(i, n) {
                if(p[i] && arr[i] > arr[i+1]) {
                    flag = true;
                    swap(arr[i], arr[i+1]);
                }
            }

        }

        flag = true;

        fori(i, n-1) {
            flag &= (arr[i] <= arr[i+1]);
        }
       
        if(flag) cout << "YES\n";
        else cout << "NO\n"; 

    }

    return 0;
}
