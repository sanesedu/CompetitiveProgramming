
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int mx = 0;

    int arr[n] = {};

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        if(arr[i] > mx) {
            mx = arr[i];
        }
    }

    int res = 0;

    for(int i = 0; i < n; ++i) {
        res += (mx - arr[i]);
    }

    cout << res << endl;

    return 0;
}
