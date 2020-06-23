
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    getline(cin, s);

    string res = "";

    for(int i = 1; i < s.length(); i += 3){
        if(s[i] != '}'){
            if(res.find(s[i]) == string::npos) res += s[i];
        }
    }

    cout << res.length() << "\n";

    return 0;
}
