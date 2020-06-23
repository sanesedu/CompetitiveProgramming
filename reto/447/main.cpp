
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
    
    int l, r;

    while(cin >> l) {
        if(l == 0) break;

        cin >> r;

        vector<int> arr(r);

        fori(i, r) cin >> arr[i];

        bool flag = false;

        for(int i = 0; i < r && !flag; ++i) {
            for(int j = i+1; j < r && !flag; ++j) {
                if(arr[i] != arr[j] && l % abs(arr[i] - arr[j]) == 0) flag = true;
            }
        }

        if(flag) cout << "SI\n";
        else cout << "NO\n";
    }

    return 0;
}
