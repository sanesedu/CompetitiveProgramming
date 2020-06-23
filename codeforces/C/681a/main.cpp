
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

    long long n, a;
    string s;
    vector<pair<string, long long>> v;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    cin >> n;

    while(n--) {
        cin >> s;

        if(s == "insert") {
            cin >> a;
            pq.push(a);
            v.pb(make_pair("insert", a));
        } else if(s == "removeMin") {
            if(pq.empty()) {
                pq.push(0);
                v.pb(make_pair("insert", 0));
            }
            pq.pop();
            v.pb(make_pair("removeMin", 0));
        } else {
            cin >> a;
            
            while(pq.size() && pq.top() < a) {
                pq.pop();
                v.pb(make_pair("removeMin", 0)); 
            }

            if(pq.empty()) {
                pq.push(a);
                v.pb(make_pair("insert", a));
            } else if(pq.top() > a) {
                pq.push(a);
                v.pb(make_pair("insert", a));
            }

            v.pb(make_pair("getMin", a));
        }
    }

    cout << v.size() << '\n';
    
    fori(i, v.size()) {
        if(v[i].first == "removeMin") {
            cout << v[i].first << '\n';
        } else {
            cout << v[i].first << " " << v[i].second << '\n';
        }
    }

    return 0;
}
