
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

    int n;

    string name, score;

    while(cin >> n) {
        if(n == 0) break;
        
        cin.ignore();

        map<string, int> m;

        fori(i, n) {
            
            getline(cin, name); 
            getline(cin, score); 

            if(score == "INCORRECTO") --m[name];
            else ++m[name];
        }

        map<string, int>::iterator it;

        for(it = m.begin(); it != m.end(); ++it) {
            if(it->second != 0) {
                cout << it->first << ", " << it->second << endl;
            }
        } 
        cout << "---\n";
    }

    return 0;
}
