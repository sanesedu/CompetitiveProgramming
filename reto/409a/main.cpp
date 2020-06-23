
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, group, total, res;
    cin >> t;

    while(t--) {
        cin >> group >> total;

        int arr[total];

        fori(i, total) cin >> arr[i];

        sort(arr, arr + total);

        res = 0;

        if(total >= group) {
            --group; //0-indexed array

            for(int i = group; i < total; ++i) {
                //checking only max and min height of group is sufficient, as array is sorted
                if(arr[i] - arr[i - group] <= 15) {
                    ++res;
                    i += group; //we move to the next group, avoiding taking into account already used values
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
