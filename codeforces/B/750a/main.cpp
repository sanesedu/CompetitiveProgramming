
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    long long t;
    string s;

    long long pos = 0;

    bool b = true;

    for(int i = 0; i < n; ++i) {
     
        cin >> t >> s;

        if(s == "South") {
            pos += t;
            if(pos > 20000) {
                b = false;
            } 
        } else if(s == "North") {
            pos -= t;
            if(pos < 0) {
                b = false; 
            } 
        } else {
            if(pos == 0 || pos == 20000) {
                b = false;
            }
        }
    }

    if(b && pos == 0) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
