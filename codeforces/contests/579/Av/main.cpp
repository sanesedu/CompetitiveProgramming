
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, n;
    cin >> q;

    for(int i = 0; i < q; ++i) {
        cin >> n; 

        int arr[n] = {};

        cin >> arr[0];

        bool b = true;

        for(int j = 1; j < n; ++j) {
            cin >> arr[j];
            if(abs(arr[j-1] - arr[j]) != 1 && abs(arr[j-1] - arr[j]) != (n-1)) b = false;
        } 

        if(b) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
