
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

    int q, sum;
    cin >> q;

    string s;

    while(q--) {
        cin >> sum >> s;

        long long res, temp;

        deque<int> dq;

        res = temp = 0;
    
        fori(i, s.length()) {
            temp += s[i] - '0';
            dq.pb(s[i] - '0');

            if(temp == sum) ++res;
        
            while(temp > sum) {
                temp -= dq.front();
                dq.pop_front();

                if(temp == sum) ++res;
            } 
        }

        cout << res << endl;
    }

    return 0;
}
