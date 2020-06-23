
#include <iostream>

using namespace std;

int main() {

    string s;

    int l = 0;

    cin >> s;

    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '4' || s[i] == '7') ++l;
    }

    s = to_string(l);

    bool lucky = true;

    for(int i = 0; i < s.length() && lucky; ++i){
        if(s[i] != '4' && s[i] != '7') lucky = false;
    }

    if(lucky) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
