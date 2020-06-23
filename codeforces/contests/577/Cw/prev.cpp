
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k, temp;

    cin >> n >> k;

    long long arr[n] = {};

    for(long long i = 0; i < n; ++i) cin >> arr[i];

    long long size = sizeof(arr) / sizeof(arr[0]);

    bool b = true;

    long long j;

    for(j = n/2; j < n-1 && b; ++j) {
        k -= (arr[n-1] - arr[j]);
        if(k < 0) {
            k += (arr[n-1] - arr[j]);
            b = false;
        }
    }

    long long res = 0;

    if(b) {
        res = k / (n - n/2);
    } else {
        res = arr[j + 1]
    }        
 
    cout << res << "\n";

    return 0;
}
