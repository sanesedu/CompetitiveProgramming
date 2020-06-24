
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define N 16

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    string song[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    int n, id, w;
    cin >> n; 

    vector<string> names(n);

    fori(i, n) cin >> names[i];
    
    id = 0;
    w = 0;

    bool end = false;

    while(!end) {
        w = 0;
        while(w < N) {
            if(id == n) {
                end = true;
                id = 0;
            }
            cout << names[id++] << ": " << song[w++] << endl;
        }
    } 

    return 0;
}
