
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
    
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    set<int> dist;

    fori(i, n) {
        cin >> arr[i];
        dist.insert(arr[i]);
    }

    if(dist.size() < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        set<int>::iterator it = dist.begin();

        while(k--) {
            cout << distance(arr.begin(), find(arr.begin(), arr.end(), *it)) + 1 << " ";
            ++it;
        }
        cout << endl;
    }

    return 0;
}
