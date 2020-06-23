
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;

    cin >> n;

    int arr[n] = {};

    for(int i = 0; i < n; ++i){
        cin >> temp;
        arr[i] = temp;
    }

    int size = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + size);

    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}
