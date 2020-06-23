
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m;
    cin >> n >> m;

    //until the mth day the barn will remain full, as input > output
    //since that day, the barn will lose 1, 2, 3, ..., x. We need to find when remaining <= m

    if(m >= n) cout << n << "\n";
    else {
    
        n -= m;

        long long l = 0, r = 2e9;
        while(l < r) {
            long long mid = (l+r) / 2;
            long long value = mid * (mid+1) / 2;

            if(value >= n) { //we decrease to find first day that meets condition
                r = mid;
            } else { //we increase to find first day that meets condition
                l = mid + 1;
            }
        }

        cout << l + m << "\n";

    }

    return 0;
}
