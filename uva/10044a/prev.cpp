
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define INF 1e17

using namespace std;

map<string, long long> m;

void print() {
    
    map<string, long long>::iterator it;

    for(it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

}

string enumb(vector<string> arr) {
    
    vector<string>::iterator it;
    string res = "";
    long long lower = INF;

    for(it = arr.begin(); it != arr.end(); ++it) {
        if(m.find(*it) != m.end()) {
            if(m[*it] <= lower) {
                lower = m[*it];
                res = *it;
            }
        } 
    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long q, n, p, commas;
    string temp, names, test;
    cin >> q;

    m["Erdos, P."] = 0;

    fori(i, q) {
        cin >> n >> p;

        fori(j, n+1) {
            getline(cin, temp);
            names = temp.substr(0, temp.find(":"));
            
            vector<string> nameArr;
            istringstream f(names);
            string s, prev;   
            bool app = false;

            while (getline(f, s, ',')) {
                if(app) {
                    prev += ",";
                    prev += s;
                    prev.erase(prev.begin(), std::find_if(prev.begin(), prev.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
                    nameArr.pb(prev);
                }
                prev = s;
                app = !app;
            }   

            string aux = enumb(nameArr);
            long long lowest;

            if(aux == "" || m[aux] == INF) {
                lowest = INF;
            } else {
                lowest = m[aux] + 1;
            }

            vector<string>::iterator it;

            for(it = nameArr.begin(); it != nameArr.end(); ++it) {
                if(m.find(*it) != m.end()) {
                    if(m[*it] > lowest) {
                        m[*it] = lowest;
                    }
                } else {
                    m[*it] = lowest;
                } 
            }
        }

        cout << "Scenario " << i+1 << endl;

        while(p--) {
            getline(cin, test);
            cout << test << " ";
            if(m[test] >= INF) {
                cout << "infinity" << endl;
            } else {
                cout << m[test] << endl;
            } 
        }
    }

    return 0;
}
