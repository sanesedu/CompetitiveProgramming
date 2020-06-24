
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

class SegmentTree {

    private:
        vector<int> arr;
        map<int, pair<int, int>> freqs;
        int n;
        
        int left(int p) {
            return (p << 1);
        }

        int right(int p) {
            return (p << 1) + 1;
        }

        void build(int p, int l, int r) {
            if(l == r) {
                st[p] = make_pair(arr[l], 1);
            } else {
                build(left(p), l, (l+r)/2);
                build(right(p), (l+r)/2 + 1, r);
                pair<int, int> p1 = st[left(p)];
                pair<int, int> p2 = st[right(p)];
                if(p1.first == p2.first) {
                    st[p].first = p1.first;
                    st[p].second = p1.second + p2.second;
                } else if(p1.second >= p2.second) {
                    st[p] = p1;
                } else {
                    st[p] = p2;
                }
            }
        }

        pair<int, int> mode(int p, int l, int r, int i, int j) {
            
            if(i > r || j < l) return make_pair(-1, -1);
            if(l >= i && r <= j) return st[p];

            pair<int, int> p1 = mode(left(p), l, (l+r)/2, i, j);
            pair<int, int> p2 = mode(right(p), (l+r)/2 + 1, r, i, j);

            if(p1.second == -1) return p2;
            if(p2.second == -1) return p1; 
            
            if(p1.first == p2.first) {
                return make_pair(p1.first, p1.second + p2.second);
            } else if(p1.second > p2.second) {
                return p1;
            } else {
                return p2;
            }
        }

    public:
        SegmentTree(const vector<int> &_a) {
            arr = _a;
            n = (int) arr.size();
            build(1, 0, n-1);
        }

        pair<int, int> mode(int i, int j) {
            return mode(1, 0, n-1, i, j);
        }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, q, a, b;

    while(cin >> n) {
        if(n == 0) break;
        cin >> q;
        vector<int> arr(n);
        fori(i, n) cin >> arr[i];
        SegmentTree stree(arr);
        while(q--) {
            cin >> a >> b;
            pair<int, int> res = stree.mode(a, b);
            cout << res.second << endl;
        }
    }

    return 0;
}
