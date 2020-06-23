
#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    map<int, int> home;

    pair<int, int> game[n];

    for(int i = 0; i < n; ++i) {
        cin >> game[i].first >> game[i].second;
        ++home[game[i].first];
    }

    int h, a;
    int min = (n-1);

    for(int i = 0; i < n; ++i) {
        h = min + home[game[i].second];
        a = 2*min - h;

        cout << h << " " << a << "\n";
    }

    return 0;
}
