
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
    
    int n, s;
    cin >> n;

    fori(i, n) {
        cin >> s;

        vector<int> arr(s-1);

        fori(j, s-1) cin >> arr[j];
    
        int l, lprev, rprev;

        lprev = rprev = l = 0;

        int res = -1000000000;
        int cur = 0;

        fori(j, s-1) {
            cur += arr[j];
            if(cur > res) {
                res = cur;
                lprev = l;
                rprev = j+1;
            } else if(cur == res) {
                if(j - l > rprev - lprev) {
                    lprev = l;
                    rprev = j+1;
                } 
            }
            if(cur < 0) {
                cur = 0;
                l = j+1;
            }
        }

        if(res < 0) cout << "Route " << i+1 << " has no nice parts" << endl;
        else cout << "The nicest part of route " << i+1 << " is between stops " << lprev+1 << " and " << rprev + 1 << endl;

    }

    return 0;
}
