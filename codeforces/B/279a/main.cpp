
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, t, temp;

    cin >> n >> t;

    long long arr[n + 1] = {};

    long long res = 0;
    long long prev = 0;

    for(long long i = 1; i <= n; ++i) {
        cin >> temp;
        arr[i] = arr[i-1] + temp;
        if(arr[i] - arr[prev] > t) ++prev;
        res = max((i - prev), res);
    }

    cout << res << "\n";
    
    return 0;
}
