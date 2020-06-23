
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

    int y, w;
    cin >> y >> w;

    int mx = max(y, w);

    switch(mx) {

        case 0:
            cout << "1/1" << endl;
            break;

        case 1:
            cout << "1/1" << endl;
            break;
        
        case 2:
            cout << "5/6" << endl;
            break;
        
        case 3:
            cout << "2/3" << endl;
            break;

        case 4:
            cout << "1/2" << endl;
            break;

        case 5:
            cout << "1/3" << endl;
            break;

        case 6:
            cout << "1/6" << endl;
            break;

    }

    return 0;
}
