
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

class SegmentTree {
    private:
        vi arr, st;
        int n;
        int left(int p) { return p << 1; }
        int right(int p) { return (p << 1) + 1; }

        void build(int p, int l, int r) {
            if(l == r) {
                st[p] = arr[l];
            } else {
                build(left(p), l, (l+r)/2);
                build(right(p), (l+r)/2 + 1, r);
                
                st[p] = st[left(p)] + st[right(p)];
            }
        }

        int query(int p, int l, int r, int i, int j) {
            if(i > r || j < l) return 0;
            if(l >= i && j >= r) return st[p];

            return query(left(p), l, (l+r)/2, i, j) + query(right(p), (l+r)/2 + 1, r, i, j);
        }

        void update(int p, int l, int r, int pos, int nval) {
            if(l == r) {
                st[p] = nval;
            } else {
                int m = (l+r)/2;

                if(pos <= m) update(left(p), l, m, pos, nval);
                else update(right(p), m+1, r, pos, nval);

                st[p] = st[left(p)] + st[right(p)];
            } 
        }

        public:
            SegmentTree(vi &a) {
                arr = a;
                n = (int) arr.size();
                st.assign(4*n, 0);
                build(1, 0, n-1);
            }

            int query(int i, int j) {
                return query(1, 0, n-1, i, j);
            }

            void update(int pos, int nval) {
                update(1, 0, n-1, pos, nval);
            }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n, x, y;
    string c;

    bool b;

    int i = 0;

    while(cin >> n, n) {
        
        if(i) cout << endl;
        ++i;
        
        vector<int> arr(n);

        fori(i, n) cin >> arr[i];

        SegmentTree st(arr);

        b = true;

        cout << "Case " << i << ":" << endl;

        while(b) {
            cin >> c;
            if(c == "END") b = false;
            else {
                cin >> x >> y;
                
                --x;

                if(c == "S") {
                    st.update(x, y);
                } else {
                    --y;
                    cout << st.query(x, y) << endl;
                }
            }
        }
    }

    return 0;
}
