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

    int q, t;
    cin >> q;

    vector<int> toy, box;

    while(q--) {
        fori(i, 3) {
            cin >> t;
            toy.pb(t);
        }

        fori(i, 3) {
            cin >> t;
            box.pb(t);
        }

        sort(all(toy));
        sort(all(box));

        if(box[0] > toy[0] && box[1] > toy[1] && box[2] > toy[2]) {
            cout << "SIRVE\n";
        } else {
            cout << "NO SIRVE\n";
        }

        toy.clear();
        box.clear();
    }

    return 0;
}
