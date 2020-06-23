
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

vector<int> arr;
int pos;

bool solve() {

    ++pos;

    int node = arr[pos];

    if(node == -1) return true;

    bool res;
    
//    cout << "left of " << node << " is " << arr[pos+1] << " " << (node > arr[pos+1]) << endl;

    int left = arr[pos+1];

    if(left != -1) {
        res = solve() && (node > left);    
    } else {
        res = solve();
    }

 //   cout << "right of " << node << " is " << arr[pos+1] << " " << (node < arr[pos+1]) << endl;
   
    int right = arr[pos+1];

    if(right != -1) {
        res = (solve() && (node < right)) && res;
    } else {
        res = solve() && res;
    }
    
  //  cout << "result " << node << " is " << res << endl;

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q, t;

    cin >> q;

    cin.ignore();

    string line;

    while(q--) {
        
        getline(cin, line);

        stringstream ss(line);

        while(ss >> t) {
            arr.pb(t);
        }

        pos = -1;

        bool res = solve();

        if(res) cout << "SI\n";
        else cout << "NO\n";
        
        arr.clear();
    }

    return 0;
}
