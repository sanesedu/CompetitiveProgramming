
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define n_unique 200005

using namespace std;

class SegmentTree {

    private:
        vector<int> arr, st;
        vector<pair<int, int>> freqs;
        int n;
        
        int left(int p) {
            return (p << 1);
        }

        int right(int p) {
            return (p << 1) + 1;
        }

        int build(int p, int l, int r) {
            if(l == r) {
                st[p] = arr[l];
            } else {
                int lval = build(left(p), l, (l+r)/2);
                int rval = build(right(p), (l+r)/2 + 1, r);
                int lfreq = getFreq(lval, l, r);
                int rfreq = getFreq(rval, l, r);
                
                if(arr[(l+r)/2] == arr[(l+r)/2 + 1]) {
                    int split_freq = getFreq(arr[(l+r)/2], l, r);
                    if(split_freq > lfreq) {
                        st[p] = (split_freq > rfreq) ? arr[(l+r)/2] : rval;
                    } else {
                        st[p] = (lfreq > rfreq) ? lval : rval;
                    } 
                } else {
                    st[p] = (lfreq > rfreq) ? lval : rval;
                }
            }
            return st[p];
        }

        int rfq(int i, int j, int L, int R, int idx) {
            if(R < i || j < L) return n_unique;
            if(i <= L && R <= j) return st[idx];

            int left_val = rfq(i, j, L, (L+R)/2, left(idx));
            int right_val = rfq(i, j, ((L+R)/2)+1, R, right(idx));
            int lo = i, hi = j, left_freq, right_freq;
            
            if(i < L) lo = L;
            if(R < j) hi = R;
            
            if(left_val != n_unique) left_freq = getFreq(left_val, lo, hi);
            if(right_val != n_unique) right_freq = getFreq(right_val, lo, hi);
            
            // detect "split" ranges and take them into account
            
            if(arr[(L+R)/2] == arr[((L+R)/2)+1]) {
                int split_freq = getFreq(arr[(L+R)/2], lo, hi);
                if(left_val == n_unique) return (split_freq > right_freq) ? arr[(L+R)/2] : right_val;
                if(right_val == n_unique) return (split_freq > left_freq) ? arr[(L+R)/2] : left_val;
                if(split_freq > left_freq) {
                    return (split_freq > right_freq) ? arr[(L+R)/2] : right_val;
                } else {
                    return (left_freq > right_freq) ? left_val : right_val;
                }
            } else {
                if(left_val == n_unique) return right_val;
                if(right_val == n_unique) return left_val;
                return (left_freq > right_freq) ? left_val : right_val;
            }
        }
    
    public:
        SegmentTree(vector<int> &_arr) {
            arr = _arr;
            freqs.assign(n_unique, make_pair(-1, -1));
            int last = n_unique;
            for(int i=0; i<(int)arr.size(); i++) {
                if(arr[i] != last) {
                if(i > 0) freqs[last+100000].second = i-1;
                freqs[arr[i]+100000].first = i;
                }
                last = arr[i];
            }
            freqs[last+100000].second = ((int)arr.size())-1;
            n = arr.size();
            st.assign(4*n, 0);
            build(0, n-1, 1);
        }
        
        int rfq(int i, int j) {
            return rfq(i, j, 0, n-1, 1);
        }

        int getFreq(int n, int i, int j) {
            int lo = freqs[n+100000].first, hi = freqs[n+100000].second;
            if(lo <= i && j <= hi) return j-i+1;
            else if(i < lo && j <= hi) return j-lo+1;
            else if(lo <= i && hi < j) return hi-i+1;
            else return hi-lo+1;
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
            --a;
            --b;
            int val = stree.rfq(a, b);
            int res = stree.getFreq(val, a, b);
            cout << res << endl;
        }
    }

    return 0;
}
