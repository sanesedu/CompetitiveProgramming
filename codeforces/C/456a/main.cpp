
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const long long M = 1e5 + 5;

    long long n, x; 
    cin >> n;

    long long arr[M] = {0};

    for(long long i = 0; i < n; ++i) cin >> x, ++arr[x];

    long long res[M] = {0};

    for(long long i = 1; i < M; ++i) {
        res[i] = res[i-1];
        if(i >= 2) {
            res[i] = max(res[i], res[i-2] + arr[i] * i);
        } else {
            res[i] = max(res[i], i * arr[i]);
        }
    }

    cout << *max_element(res, res+M) << endl;

    return 0;
}
