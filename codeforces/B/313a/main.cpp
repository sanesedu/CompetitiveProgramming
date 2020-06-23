
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> s;

    int mat[s.length()] = {};

    for(int i = 1; i < s.length(); ++i) {
        mat[i] = mat[i-1];
        if(s[i] == s[i-1]) ++mat[i];
    }

    int m, l, r;

    cin >> m;

    int res;

    for(int i = 0; i < m; ++i){
        cin >> l >> r;
        
        --l;
        --r;
        
        cout << mat[r] - mat[l] << "\n";
    }

    return 0;
}
