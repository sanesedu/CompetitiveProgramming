
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    string s;
    cin >> s;
    
    bool par = false;
    int lg = 0;
    int npar = 0;
    int mx = 0;

    for(int i = 0; i < n; ++i) {
        if(s[i] == '_') {
            if(lg > 0) {
                if(!par) mx = max(mx, lg);
                else ++npar;
            }
            lg = 0;
        } else if(s[i] == '(') {
            par = true;
            if(lg > 0) {
                mx = max(mx, lg);
            }
            lg = 0;
        } else if(s[i] == ')') {
            par = false;
            if(lg > 0) {
                ++npar;
            }
            lg = 0;
        } else {
            ++lg;
        }
    }

    mx = max(mx, lg);

    cout << mx << " " << npar << endl;

    return 0;
}
