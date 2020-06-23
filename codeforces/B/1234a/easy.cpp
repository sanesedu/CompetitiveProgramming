
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

    int t, n, k;
    cin >> n >> k;
    deque<int> dq;

    fori(i, n) {
        cin >> t;
        if(find(all(dq), t) != dq.end()) continue;
        if((int) dq.size() == k) {
            dq.pop_back();
        }
        dq.push_front(t);
    }

    cout << dq.size() << endl;

    while(!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;

    return 0;
}
