
#include <iostream>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    bool end = true;

    string a(m, '#');
    string b(m-1, '.');
    b.append("#");
    string c("#");
    c.append(b.begin(), b.end()-1);

    for(int i = 0; i < n; ++i) {
        if(i % 2 == 0) {
            cout << a << "\n";
        } else {
            if(end) {
                cout << b << "\n";
                end = false;
            } else {
                cout << c << "\n";
                end = true;
            }
        }
    }

    return 0;
}
