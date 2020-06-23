
#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    map<string, int> m;
    m["Tetrahedron"] = 4;
    m["Cube"] = 6;
    m["Octahedron"] = 8;
    m["Dodecahedron"] = 12;
    m["Icosahedron"] = 20;

    int n;
    cin >> n;

    long long res = 0;

    string s;

    for(int i = 0; i < n; ++i) {
        cin >> s;
        res += m[s];
    }

    cout << res << endl;

    return 0;
}
