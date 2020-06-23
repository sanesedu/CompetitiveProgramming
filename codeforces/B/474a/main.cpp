
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    long long temp;

    cin >> n;

    long long arr[n + 1] = {};

    cin >> arr[1];

    for(int i = 2; i <= n; ++i){
        cin >> temp;
        arr[i] = arr[i-1] + temp;
    }

    cin >> m;

    for(int j = 0; j < m; ++j) {
        cin >> temp;

        int l, r, m;
        l = 1;
        r = n;

        while(l <= r){
            m = (l+r) / 2;
            
            if(arr[m-1] < temp && arr[m] >= temp) {
                cout << m << "\n";
                break;
            } else if(temp > arr[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }

    return 0;
}
