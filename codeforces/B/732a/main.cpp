
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int arr[n] = {};

    for(int i = 0; i < n; ++i) cin >> arr[i];

    int added = 0;
    int temp = 0;

    for(int i = 1; i < n; ++i) {
        temp = max(0, k - arr[i] - arr[i-1]);
        added += temp;
        arr[i] += temp;
    }

    cout << added << "\n";

    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}
