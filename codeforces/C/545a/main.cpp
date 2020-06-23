
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

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    pair<int, int> arr[n] = {};

    fori(i, n) cin >> arr[i].first >> arr[i].second;

    int res = 2; //first and last tree can always be cut down
    
    forb(i, 1, n-2) {
        
        if(arr[i-1].first < arr[i].first - arr[i].second) { //cut down to left
            ++res;
        } else if(arr[i+1].first > arr[i].first + arr[i].second) { //cut down to right
                ++res;
                arr[i].first = arr[i].first + arr[i].second; //update occupied space
        }
    }

    cout << res << endl;

    return 0;
}
