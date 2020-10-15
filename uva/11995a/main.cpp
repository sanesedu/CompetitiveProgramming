
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, a, b, tq, ts, tpq;

    while(cin >> n) {
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;

        bool isq = true;
        bool iss = true;
        bool ispq = true;

        while(n--) {
            cin >> a >> b;

            if(a == 1) {
                q.push(b);
                s.push(b);
                pq.push(b);
            } else {
                if(!q.empty()) {
                    tq = q.front();
                    if(tq != b) isq = false;
                    q.pop();
                } else {
                    isq = false;
                }

                if(!s.empty()) {
                    ts = s.top();
                    if(ts != b) iss = false;
                    s.pop();
                } else {
                    iss = false;
                }

                if(!pq.empty()) {
                    tpq = pq.top();
                    if(tpq != b) ispq = false;
                    pq.pop();
                } else {
                    ispq = false;
                }
            }
        }

        if(!isq && !iss && !ispq) {
            cout << "impossible" << endl;
        } else if((isq && iss) || (isq && ispq) || (iss && ispq)) {
            cout << "not sure" << endl;
        } else if(iss) {
            cout << "stack" << endl;
        } else if(isq) {
            cout << "queue" << endl;
        } else if(ispq) {
            cout << "priority queue" << endl;
        }
    }

    return 0;
}
