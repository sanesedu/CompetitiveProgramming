
#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

bool vis[(long long)1e5+5];
map<long long, int> marr;
map<long, vector<long>> m;

long long bfs(long long ini, long long goal, long long length) {
    
    if(vis[marr[ini]]) {
        if(ini != goal) {
            --length;
        } 
    }

    if(length > 0) vis[marr[ini]] = true;

    for(long long x: m[ini]) {        
        if(!vis[marr[x]]) {
            bfs(x, goal, length + 1);
        }
    }

    return length;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    long long arr[n] = {};

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        marr[arr[i]] = i;
    }


    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(arr[i] & arr[j] != 0) {
                m[arr[i]].push_back(arr[j]);
                m[arr[j]].push_back(arr[i]);
            }
        }
    }

    long long min, temp;

    min = -1;

    for(int i = 0; i < n; ++i) {
        memset(vis, false, sizeof(vis));
    
        temp = bfs(arr[i], arr[i], 0);

        if(vis[i]) {
            if(temp < min || min == -1) {
                min = temp;
            }
        }
    }

    cout << min << endl;

    return 0;
}
