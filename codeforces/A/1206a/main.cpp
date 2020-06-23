
#include <iostream>
#include <set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, temp;
    cin >> n;

    set<int> a;

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        a.insert(temp);
    }
    
    int m;
    cin >> m;

    set<int> b;

    for(int i = 0; i < m; ++i) {
        cin >> temp;
        b.insert(temp);
    }

    set<int>::iterator it = a.end();
    --it;

    set<int>::iterator jit = b.end();
    --jit;

    cout << *it << " " << *jit << endl;

    return 0;
}
