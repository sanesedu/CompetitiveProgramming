
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    pair<int, int> arr[n];

    for(int i = 0; i < n; ++i) {
        cin >> arr[i].second >> arr[i].first;
    }

    sort(arr, arr + n);

    int res = 0;
    int c = 1;

    for(int i = n-1; i >= 0 && c > 0; --i) {
        res += arr[i].second;
        c += arr[i].first - 1;
    }

    cout << res << endl;

    return 0;
}
