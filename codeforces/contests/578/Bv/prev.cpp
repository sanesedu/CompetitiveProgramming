
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    long long n, m, k;

    for(int i = 0; i < t; ++i) {
        cin >> n >> m >> k;
    
        long long arr[n] = {};

        long long temp, prev;

        bool res = true;

        cin >> prev;

        for(long long j = 1; j < n && res; ++j) {
            cin >> arr[j];
            if(arr[j-1] >  arr[j]) {
                m += (arr[j-1] - arr[j] + k); //we add max number blocks
            } else if(arr[j-1] < arr[j]) {
                if(arr[j] - arr[j-1] > k) {
                    m -= ((arr[j] - arr[j-1]) - k); //we remove min number blocks
                    if(m < 0) res = false;
                } 
            }
        }

        if(res) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
