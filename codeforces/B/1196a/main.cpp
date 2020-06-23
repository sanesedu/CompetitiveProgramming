
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long q, n, k, step;

    cin >> q;

    for(long long i = 0; i < q; ++i) {
        cin >> n >> k;

        long long arr[n] = {};
        long long odds = 0;

        for(long long j = 0; j < n; ++j) {
            cin >> arr[j];
            if(arr[j] % 2 != 0) ++odds;
        }

        //1. there will be at least one group without odd number -> sum even. 
        //2. k % 2 == 1 & odds % 2 == 0 even number of odds but odd number of groups, so the remaining odd number is attached to another -> even sum
        if(odds < k || odds % 2 != k % 2) { 
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for(long long h = 0; h < n; ++h) {
            if(k == 1) break; //we should only print n
            if(arr[h] % 2 == 1) {
                 cout << h + 1 << " "; //+1 for regular positioning
                 --k;
            }
        }
        cout << n << "\n";
    }

    return 0;
}
