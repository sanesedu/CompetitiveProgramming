
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

void lis(vector<int> arr) {
    
    int n = arr.size();

    int p[n];
    int res[n];

    fori(i, n) {
        p[i] = -1;
        res[i] = 1;
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(arr[i] > arr[j]) {
                if(res[i] < res[j] + 1) {
                    res[i] = res[j] + 1;
                    p[i] = j;
                }
            }
        }
    }

    int len = 0;
    int maxindex = 0;

    for(int i = 0; i < n; ++i) {
        if(res[i] > len) {
            len = res[i];
            maxindex = i;
        }
    }

    cout << "Max hits: " << len << endl;
    
    vector<int> sol;

    while(maxindex != -1) {
        sol.pb(arr[maxindex]);
        maxindex = p[maxindex];
    } 
   
    reverse(all(sol));

    vector<int>::iterator it;

    for(it = sol.begin(); it != sol.end(); ++it) {
        cout << *it << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int q;
    cin >> q;

    string s;

    getline(cin, s);
    getline(cin, s);

    while(q--) {
        
        vector<int> arr;

        while(getline(cin, s)) {
            if(s.empty()) break;
            arr.pb(stoi(s));
        }
        
        lis(arr); 
        
        if(q) cout << endl;
    }

    return 0;
}
