
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

    long long a, b, n, p, res;

    while(cin >> n) {
        if(n == 0) break;
  
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        while(n--) {
            cin >> p;
            pq.push(p);
        }

        res = 0;

        while(pq.size() > 1) {
            a = pq.top();
            pq.pop();
            
            b = pq.top();
            pq.pop();
            
            res += (a + b);
            pq.push(a + b);
        }

        cout << res << endl;
    }

    return 0;
}
