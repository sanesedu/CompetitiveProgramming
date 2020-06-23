
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    long long arr[m+1] = {};

    for(int i = 0; i <= m; ++i) cin >> arr[i];

    int res = 0;
    int temp, count;
    string s;

    for(int i = 0; i < m; ++i) {
        temp = arr[i] ^ arr[m];

        s = bitset<64>(temp).to_string();

        count = 0;

        for(int j = 0; j < s.length() && count <= k; ++j){
            if(s[j] == '1') ++count;
        }

        if(count <= k) ++res;
    }

    cout << res << "\n";

    return 0;
}
