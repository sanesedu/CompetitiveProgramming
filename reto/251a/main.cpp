
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

long long t, n, k;

long long solve(vector<long long> arr) {
    
    long long res = 0;

    queue<pair<long long, long long>> q;
    q.push({0, 0});
    
    bool visited[2010];
    memset(visited, false, sizeof(visited));

    while(!q.empty()) {
        
        pair<long long, long long> cur = q.front();
        q.pop();

        fori(i, n) {
            if(!visited[arr[i] + cur.first] && cur.second + 1 <= k) {
                q.push({arr[i] + cur.first, cur.second + 1});
                visited[arr[i] + cur.first] = true;
                ++res;
            }
        }
    }
    
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    cin >> t;

    while(t--) {
        cin >> n >> k;

        vector<long long> arr(n);

        fori(i, n) cin >> arr[i];
    
        cout << solve(arr) << endl;
    }

    return 0;
}
