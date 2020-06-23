
#include <iostream>
#include <cstring>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int w[600] = {};

    for(int i = 1; i <= n; ++i) cin >> w[i];

    int b[6000] = {};

    bool visited[600];

    long long total = 0;

    for(int i = 0; i < m; ++i) {

        cin >> b[i];

        memset(visited, false, sizeof(visited));

        for(int j = i - 1; j >= 0; --j) { //we have to lift all previous books to access this one
            if(b[i] == b[j]) break; //the weight to lift to access the book already added
            if(!visited[b[j]]) total += w[b[j]], visited[b[j]] = true;
        }
    }

    cout << total << endl;

    return 0;
}
