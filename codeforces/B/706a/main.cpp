
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q, h, t;

    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; ++i) {
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    cin >> q;

    long long temp;

    for(int j = 0; j < q; ++j){
        cin >> temp;
        
        cout << upper_bound(v.begin(), v.end(), temp) - v.begin() << "\n";
    }

    return 0;
}
