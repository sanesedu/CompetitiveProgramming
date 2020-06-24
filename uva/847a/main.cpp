
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
typedef pair<int, int> pi;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    ll n, turn;

    while(cin >> n){
       
        if(n == 1){
            cout << "Stan wins." << endl;
            continue;
        }
        
        turn = 0;
        
        while(n > 1){
            turn++;
            if(turn % 2 == 1) n= (n + 8) / 9;
            else n = (n + 1) / 2;
        }
                
        if(turn % 2 == 1) cout<< "Stan wins." <<endl;
        else cout << "Ollie wins." << endl;
    }

    return 0;
}
