
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool mycmp(pair<int, int> a, pair<int, int> b) {
    return (a.first < b.first) && (a.second > b.second);
}

void print(vector<pair<int, int>> v) {
    
    vector<pair<int, int>>::iterator it;

    for(it = v.begin(); it != v.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int len, n, t, v;

    while(cin >> len >> n) {
        
        vector<pair<int, int>> arr;

        fori(i, n) {
            cin >> t >> v; 
            if(t >= 0) {
                arr.pb(make_pair(t, v));
            }
        }

        sort(all(arr), mycmp);

        print(arr);

        int d = 0;
        int time = arr[0].first;

        int curr = 0;

        while(d < len) {
       
            if(curr + 1 < (int) arr.size() && arr[curr+1].first < time) {
                if((time - arr[curr+1].first) * arr[curr+1].second >= d) {
            
                    cout << "jump: " << time << endl;
                    curr++;
                    d = (time - arr[curr].first) * arr[curr].second;
                } else {
                    d += arr[curr].second;
                }
            } else {
                d += arr[curr].second;
            } 
            
            ++time;
        }
        
        cout << time << endl;

    }

    return 0;
}
