
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

    int n, w;

    while(cin >> n >> w) {
   
        vector<int> arr(n);

        fori(i, n) cin >> arr[i];

        sort(all(arr));
    
        vector<int>::iterator up = upper_bound(all(arr), w/2);

        int d = up - arr.begin();

        if(*up + arr[d-1] > w) {
            cout << d << endl;
        } else {
            cout << d+1 << endl;
        }
    }

    return 0;
}
