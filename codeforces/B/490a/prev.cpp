
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

void print(vector<int> v) {
    
    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n";
}

void prints(set<int> v) {
    
    set<int>::iterator it;

    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n, a, b;
    cin >> n;

    vector<int> fst, lst;

    vector< pair<int, int> > v;

    vector<int>::iterator fit, lit;

    set<int> s;

    fori(i, n) {
       
        cin >> a >> b;

        v.pb(make_pair(a, b));    
        
        fst.pb(a);
        lst.pb(b);

        s.insert(a);
        s.insert(b);

        lit = find(lst.begin(), lst.end(), a);
       
        if(lit != lst.end()) {
            lst.erase(remove(lst.begin(), lst.end(), a), lst.end());
            fst.erase(remove(fst.begin(), fst.end(), a), fst.end());
        }

        fit = find(fst.begin(), fst.end(), b);

        if(fit != fst.end()) {
            fst.erase(remove(fst.begin(), fst.end(), b), fst.end());
            lst.erase(remove(lst.begin(), lst.end(), b), lst.end());
        }
    }


    int res[n] = {};
    res[0] = fst[0];
    res[n-1] = lst[0];    

    s.erase(fst[0]);
    s.erase(lst[0]);

    int prev = 1;
    int post = n - 2;

    int bef = 0;
    int aft = 0;
    
    s.erase(bef);

    int m = 2;
    
    vector<pair<int, int>>::iterator it;

    while(v.size() > 0 && m < n) {

        bool l, r;
        l = r = false;

        for(it = v.begin(); it != v.end(); ++it) {
        
            if(it->first == bef && !l && m < n) {
                res[prev] = it->second;
                ++prev;
                bef = it->second;
                s.erase(bef);
                it->first = -1;
                it->second = -1;
                l = true;
                ++m;
            } 
            
            if(it->second == aft && !r && m < n) {
                res[post] = it->first;
                --post;
                aft = it->first;
                s.erase(aft);
                it->first = -1;
                it->second = -1;
                r = true;
                ++m;
            }
        }
            
    }

    if(n % 2 != 0 && s.size() > 0) {
        res[n/2] = *s.begin();
    }

    fori(i, n) {
        cout << res[i] << " ";
    }

    cout << "\n"; 
    
    return 0; 

}
