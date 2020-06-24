
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define L -1
#define R -2

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, n, id, pos;
    cin >> t;

    string s;

    while(t--) {
        cin >> n;
        cin.ignore();
        vector<int> arr(n);

        pos = 0;

        fori(i, n) {
            cin >> s;
            if(s == "LEFT") {
                arr[i] = L;
                --pos;
            } else if(s == "RIGHT") {
                arr[i] = R; 
                ++pos;
            } else {
                cin >> s >> id;
                --id;
                arr[i] = id;                

                while(id >= 0) {
                    id = arr[id];
                } 

                if(id == L) --pos;
                else if(id == R) ++pos;
            }
        }

        cout << pos << endl;
    }

    return 0;
}
