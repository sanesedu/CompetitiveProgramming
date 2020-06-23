
#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string a, b;

    cin >> n >> m;

    map<string, string> mp;

    for(int i = 0; i < m; ++i) {
        cin >> a >> b;
        mp[a] = b;
    }

    for(int j = 0; j < n; ++j){
        cin >> a;
        if(mp[a].length() < a.length()) {
            cout << mp[a] << " ";
        } else {
            cout << a << " ";
        }
    }

    cout << "\n";

    return 0;
}
