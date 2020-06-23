
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

class Word {
    public:
        string s;
        set<int> mayus;
        ll reps = 0;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, len, r;
    
    string s, res;

    set<int> tmp;

    while(cin >> n) {
        cin.ignore();

        map<string, Word> words;
        vector<string> used;

        fori(i, n) {
        
            getline(cin, s); 
           
            set<int> m;

            len = s.length();

            fori(j, len) {
                if(isupper(s[j])) {
                    m.insert(j);
                    s[j] = tolower(s[j]);
                } 
            }
            
            used.pb(s);

            words[s].reps++;
            words[s].s = s; 
            if(words[s].mayus.size() <= m.size()) words[s].mayus = m;
        }

        for(auto it = used.begin(); it != used.end(); ++it) {
            
            res = *it;

            len = res.length();

            tmp = words[res].mayus;

            fori(i, len) {
                if(tmp.find(i) != tmp.end()) cout << (char)toupper(res[i]);
                else cout << res[i];
            }
            cout << endl;
        }

        cout << "---" << endl;
    }

    return 0;
}
