
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k, temp;

    cin >> n >> k;

    long long arr[n] = {};

    cin >> arr[0];

    for(long long i = 1; i < n; ++i) {
        cin >> temp;
        arr[i] = arr[i-1] + temp;
    }

    long long min = arr[k-1];
    long long minpos = 0;

    for(long long j = k; j < n; ++j) {
        if(arr[j] - arr[j - k] < min) {
            min = arr[j] - arr[j - k];
            minpos = j - k + 1;
        }
    }

    cout << minpos + 1 << "\n";

    return 0;
}
