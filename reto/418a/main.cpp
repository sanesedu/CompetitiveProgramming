
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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int t, id, num, to;
    string line;

    cin >> t;
    cin.ignore();

    while(t--) {
       
        vector<string> program;
        map<int, int> renum;

        id = 10;

        while(getline(cin, line)) {
            stringstream ss(line);
            ss >> num;
            if(num == 0) break;
            program.pb(line);
            if(renum.find(num) == renum.end()) {
                renum[num] = id;
                id += 10;
            }
        }
        
        for(string inst: program) {
            stringstream ss(inst);
            ss >> num >> inst;
            cout << renum[num] << " " << inst;
            if(inst != "RETURN") {
                ss >> to;
                cout << " " << renum[to];
            }
            cout << endl;
        }

        cout << "---\n";
    }

    return 0;
}
