
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;

    cin >> n >> m;

    long long arr[n] = {};

    long long maxim = 0;

    for(long long i = 0; i < n; ++i) {
        cin >> arr[i];
        maxim = max(maxim, arr[i]);
    }

    long long res[n] = {};

    bool used[maxim + 1] = {false};

    res[n-1] = 1;
    used[arr[n-1]] = true;

    for(int i = n-2; i >= 0; --i) {
        res[i] = res[i+1];
        if(!used[arr[i]]){
            ++res[i];
            used[arr[i]] = true;
        } 
    }

    long long t;

    for(int i = 0; i < m; ++i){
        cin >> t;
        cout << res[t-1] << "\n";
    }

    return 0;
}
