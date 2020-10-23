
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
        vi st, arr;
        int n;
        int left(int p) { return p << 1; }
        int right(int p) { return (p << 1) + 1; }
        
        void build(int p, int l, int r) {
            if(l == r) {
                st[p] = arr[l];
            } else {
                build(left(p), l, (r+l)/2);
                build(right(p), (r+l)/2 + 1, r);
               
                st[p] = st[left(p)] * st[right(p)];
            }
        }
        
        int prod(int p, int l, int r, int i, int j) {
            if(i > r || j < l) return 1; //outside interval
            if(l >= i && r <= j) return st[p]; //inside interval
        
            int pl = prod(left(p), l, (r+l)/2, i, j);
            int pr = prod(right(p), (r+l)/2 + 1, r, i, j);
        
            return pl*pr;
        }

        void update(int p, int l, int r, int pos, int nv) {
            if(l == r) {
                st[p] = nv;
            } else {
                int m = (l + r) / 2;

                if(pos <= m) update(left(p), l, m, pos, nv);
                else update(right(p), m+1, r, pos, nv);

                st[p] = st[left(p)] * st[right(p)]; 
            }
        }

        void print(int p, int l, int r, int s) {
            fori(i, s) cout << " ";
            cout << "> ";
            cout << st[p] << endl;
            
            if(l != r) {
                print(left(p), l, (l+r)/2, s+3); 
                print(right(p), (l+r)/2 + 1, r, s+3); 
            }
        }

    public:
        SegmentTree(vi &a) {
            arr = a;
            n = (int) arr.size();
            st.assign(4*n, 1);
            build(1, 0, n-1);
        }
        
        int prod(int i, int j) {
            return prod(1, 0, n-1, i, j);
        }

        void update(int pos, int nv) {
            update(1, 0, n-1, pos, nv);
        }

        void print() {
            print(1, 0, n-1, 1);
        }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, k, a, b, res;
    char c;

    while(cin >> n >> k) {
        vector<int> arr(n);

        fori(i, n) {
            cin >> arr[i];
            if(arr[i] > 1) arr[i] = 1;
            if(arr[i] < -1) arr[i] = -1;
        }

        SegmentTree st(arr);
 //       st.print();
  //      cout << endl;

        fori(i, k) {
            cin >> c >> a >> b;
            if(c == 'C') {
                if(b > 1) b = 1;
                if(b < -1) b = -1;
                st.update(a-1, b);
                
                arr[a-1] = b;

            } else {
                res = st.prod(a-1, b-1);

                if(res == 0) cout << 0;
                else if(res < 0) cout << "-";
                else cout << "+";
            }
//            st.print();
 //       cout << endl;
        }
        cout << endl;
    }

    return 0;
}
