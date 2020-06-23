
#include <iostream>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n; 
    cin >> n;

    if(n < 0) {
        string s = to_string(n);
        int l = s[s.length()-1];
        int sl = s[s.length() - 2];
        if(l > sl) {
            s.erase(s.length()-1, 1);
        } else {
            s.erase(s.length()-2, 1);
        }

        n = stoll(s);
    }

    cout << n << endl;

    return 0;
}
