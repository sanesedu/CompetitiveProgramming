
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, temp;

    cin >> n >> h;

    int res = 0;

    for(int i = 0; i < n; ++i) {
        cin >> temp;

        if(temp > h){
            res += 2;
        } else {
            ++res;
        }
    }

    cout << res << "\n";

    return 0;
}
