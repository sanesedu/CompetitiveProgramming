
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long l;

    cin >> n >>l;

    long long arr[n] = {};

    for(int i = 0; i < n; ++i) cin >> arr[i];

    int size = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + size);

    long double radius = arr[0];
    long double curr = arr[0];

    for(int i = 1; i < n; ++i){
        curr = (arr[i] - arr[i-1]) / (long double)2;
        if(curr > radius) radius = curr;
    }

    if(l - arr[n-1] > radius) radius = l - arr[n-1];

    cout << setprecision(15) << radius << "\n";

    return 0;
}
