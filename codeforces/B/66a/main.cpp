
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
    
    int n;
    cin >> n;

    int arr[n] = {};

    int res = 0;

    fori(i, n) cin >> arr[i];

    fori(i, n) {
        
        int x, y;
        x = i - 1;
        y = i + 1;
        int total = 1;

        int height = arr[i];

        while(x >= 0) {
            if(arr[x] > height) {
                break;
            } else {
                ++total;
                height = arr[x];
            }
            --x;
        }

        height = arr[i];

        while(y < n) {
            if(arr[y] > height) {
                break;
            } else {
                ++total;
                height = arr[y];
            }
            ++y;
        }

        if(total > res) res = total;

    }

    cout << res << endl;

    return 0;
}
