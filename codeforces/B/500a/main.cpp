
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

string s[500];
bool visited[500];
map<int, vector<int>> adj;
int a[500];
int n;
vector<int> arr1, arr2;

void dfs(int l) {
    visited[l] = true;
    arr1.push_back(l); //position
    arr2.push_back(a[l]); //value
    for(int x: adj[l]) {
        if(!visited[x]) dfs(x);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        for(int j = 0; j < n; ++j) {
            if(s[i][j] == '1') {
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            dfs(i);
            sort(arr1.begin(), arr1.end()); //we order position of members of component
            sort(arr2.begin(), arr2.end()); //we order members of component
            for(int j = 0; j < arr1.size(); ++j) {
                a[arr1[j]] = arr2[j]; //each member of component is moved to its corresponding position in a
            }
            arr1.clear();
            arr2.clear();
        }
    }

    for(int i = 1; i <= n; ++i) cout << a[i] << " ";
    
    cout << endl;

    return 0;
}
