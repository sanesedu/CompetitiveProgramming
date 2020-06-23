
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int infinity = 1234567890; //from tutorial

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m; 
    cin >> n;

    vector< pair<int, int> > v(n);

    for(int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

    cin >> m;

    vector< pair<int, int> > u(m);

    for(int i = 0; i < m; ++i) cin >> u[i].first >> u[i].second;

    int mxln = -infinity;   int minrn = infinity;
    int mxlm = -infinity;   int minrm = infinity;

    for(int i = 0; i < n; ++i) {
        mxln = max(mxln, v[i].first);
        minrn = min(minrn, v[i].second);
    }

    for(int i = 0; i < m; ++i) {
        mxlm = max(mxlm, u[i].first);
        minrm = min(minrm, u[i].second);
    }

    int res = max(mxlm - minrn, mxln - minrm);

    cout << max(res, 0) << "\n";

    return 0;
}
