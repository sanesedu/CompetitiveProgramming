
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

    vector<int> arr(n);

    fori(i, n) cin >> arr[i];

    int i = 0;

    int s = 0;
    int d = 0;

    while(!arr.empty()) {
        if(arr[0] > arr[n-1]) {
            if(i % 2 == 0) s += arr[0];
            else d += arr[0];
            arr.erase(arr.begin());
        } else {
            if(i % 2 == 0) s += arr[n-1];
            else d += arr[n-1];
            arr.erase(arr.begin() + n-1);
        }
        
        ++i;
        --n;
    }

    cout << s << " " << d << endl;

    return 0;
}
