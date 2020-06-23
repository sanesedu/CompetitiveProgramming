
#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, value;

    cin >> n >> m;

    string arr[n] = {};

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    map<char, int> mp;

    int max;

    int res = 0;

    for(int j = 0; j < m; ++j) {
        cin >> value;
        mp.clear();

        max = 0;

        for(int i = 0; i < n; ++i) {
            ++mp[arr[i][j]];
            if(mp[arr[i][j]] > max) max = mp[arr[i][j]];
        }

        res += (max*value);
    }

    cout << res << "\n";

    return 0;
}
