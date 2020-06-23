
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<long long> v;

    int negs = 0;
    
    long long temp;

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        v.push_back(temp);
        if(temp <= 0) ++negs;
    }

    sort(v.begin(), v.end());

    if(negs % 2 != 0) {
        --negs;
    }

    long long res = 0;

    vector<long long>::iterator it;

    for(it = v.begin(); it != v.end(); ++it) {
        if(negs > 0) {
            res += abs(*it + 1);
            --negs;
        } else {
            res += abs(*it - 1);
        }
    }

    cout << res << endl;

    return 0;
}
