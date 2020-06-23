
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k;

    cin >> n >> k;

    long long arr[n] = {};

    for(long long i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr + n);

    long long res = arr[n/2];

    bool b = true;

    long long count = 1;

    for(long long i = n/2; i < n-1 && b; ++i) {
        if(k < (count) * (arr[i + 1] - arr[i])) { //if we do not have enough k to increase all previous elements to the value of next element
            res += (k/count); //we divide k evenly between the amount of previous elements so that all of them increase the same
            k = 0;
            b = false;
        } else {
            k -= count * (arr[i+1] - arr[i]); //we increase all previous elements to the value of the next element
            res += (arr[i+1] - arr[i]);
        }
        ++count;
    }

    if(k > 0) res += (k/count); //we have some k left, so we distribute it evenly between previous elements
 
    cout << res << "\n";

    return 0;
}
