
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

    map<char, vector<pair<int, int>>> coords;

    int n, m, x, q;
    cin >> n >> m >> x;

    string s;

    fori(i, n) {
        cin >>  s;
        fori(j, m) {
            coords[s[j]].pb(make_pair(i+1, j+1));
        }
    }

    cin >> q;
    cin >> s;

    bool imp = false;

    long long count = 0;
    map<char, int> vis; 

    fori(i, q) {
        if(s[i] < 97) { //uppercase
            if(coords.count('S')) { //there are shift keys
                if(coords.count(tolower(s[i]))){ //the letter exists in lower case
                    if(vis.count(tolower(s[i]))) count += vis[tolower(s[i])]; //if this key has already been considered before
                    else {
                        double mini = 1e9;
                        int l1, l2;
                        l1 = coords['S'].size();
                        l2 = coords[tolower(s[i])].size();

                        bool found = false;

                        fori(j, l1) {
                            fori(k, l2) {
                                double dist = sqrt(pow(coords['S'][j].first - coords[tolower(s[i])][k].first, 2) + pow(coords['S'][j].second - coords[tolower(s[i])][k].second, 2));
                                dist = ceil(dist);
                                if(dist <= x) {
                                    found = true;
                                    break;
                                }
                            }
                            if(found) break;
                        }

                        if(!found) ++count;

                        vis[tolower(s[i])] = !found;

                    }
                } else {
                    imp = true;
                    break;
                }
            } else {
                imp = true;
                break;
            }
        } else {
            if(!coords.count(s[i])) {
                imp = true;
                break;
            }
        }
    }

    if(imp) cout << -1 << endl;
    else cout << count << endl;

    return 0;
}
