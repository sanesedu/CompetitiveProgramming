
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, res;

    cin >> s;

    res = "";

    for(int i = 0; i < s.length(); ++i){
        
        if(i < s.length() - 2 && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            if(res.length() > 0){
                res += " ";
            }
            i += 2;
        } else {
            res += s[i];
        }
    }

    cout << res << "\n";

    return 0;
}
