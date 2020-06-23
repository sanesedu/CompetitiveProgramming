
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n, m;
    char c;
    cin >> n >> m >> c;

    char arr[n][m] = {};

    fori(i, n) {
        cin >> arr[i];
    }

    set<char> adj;

    fori(i, n) {
        fori(j, m) {
            if(arr[i][j] == c) {
                if(i > 0 && arr[i-1][j] != '.' && arr[i-1][j] != c) adj.insert(arr[i-1][j]);
                if(j > 0 && arr[i][j-1] != '.' && arr[i][j-1] != c) adj.insert(arr[i][j-1]);
                if(i < n-1 && arr[i+1][j] != '.' && arr[i+1][j] != c) adj.insert(arr[i+1][j]);
                if(j < m-1 && arr[i][j+1] != '.' && arr[i][j+1] != c) adj.insert(arr[i][j+1]);
            }
        }
    }
    cout << adj.size() << endl;

    return 0;
}
