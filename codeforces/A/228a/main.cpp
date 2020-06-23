
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long s[4] = {};

    cin >> s[0] >> s[1] >> s[2] >> s[3];

    bool f;

    int res = 0;

    for(int i = 0; i < 3; ++i){
        f = true;
        for(int j = i + 1; j < 4 && f; ++j){
            if(s[i] == s[j]) {
                f = false;
            }
        }

        if(f) ++res;
    }

    res = 3 - res;

    cout << res << "\n";

    return 0;
}
