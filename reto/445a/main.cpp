
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n, res;

    while(cin >> n) {
        
        vector<pair<int, int>> arr(n);
        priority_queue<int, vector<int>, greater<int>> pq;
    
        res = 0;

        fori(i, n) {
            cin >> arr[i].first >> arr[i].second; 
        }

        sort(all(arr), cmp);
    
        fori(i, n) {
            if(pq.empty()) pq.push(arr[i].second);
            else {
                while(!pq.empty() && pq.top() <= arr[i].first) pq.pop();
                pq.push(arr[i].second);
            }
            res = max(res, (int) pq.size());
        }

        cout << res - 1 << endl;
    }

    return 0;
}
