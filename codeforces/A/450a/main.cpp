
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

    int n, m, t;
    
    cin >> n >> m;

    int arr[n] = {};

    queue<int> q;

    fori(i, n) {
        cin >> arr[i];
        q.push(i);
    }

    while(q.size() > 1) {
        t = q.front();
        q.pop();
        arr[t] -= m;
        if(arr[t] > 0) q.push(t);
    }

    cout << q.front() + 1 << endl;

    return 0;
}
