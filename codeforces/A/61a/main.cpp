
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;

    cin >> a >> b;
    
    string res = "";

    int curr;

    for(int i = 0; i < a.length(); ++i){
        curr = ((int)a[i]) ^ ((int)b[i]);
        res += to_string(curr);
    }

    cout << res <<  "\n";

    return 0;
}
