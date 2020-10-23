
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

    string line, res, cur;
    int best, tmp1, tmp2, tmp3, sum;

    vector<int> vals(9);

    char letters[3] = {'B', 'G', 'C'};
    char colors[3];

    while(getline(cin, line)) {
        stringstream ss(line);

        fori(i, 9) {
            ss >> vals[i];
        }

        best = INT_MAX;
        res = "";

        fori(i, 3) {
            tmp1 = 0;
            colors[0] = letters[i];
            fori(j, 3) {
                if(j != i) tmp1 += vals[j]; 
            }

            fori(j, 3) {
                if(j != i) {
                    tmp2 = 0;
                    colors[1] = letters[j];

                    fori(k, 3) {
                        if(k != j) tmp2 += vals[k + 3];
                    }

                    fori(k, 3) {
                        if(k != j && k != i) {
                            tmp3 = 0;
                            colors[2] = letters[k];

                            fori(h, 3) {
                                if(h != k) tmp3 += vals[h + 6];
                            }
                
                            sum = tmp1 + tmp2 + tmp3;
                            
                            cur = "";
                            fori(l, 3) cur.pb(colors[l]);

                            if(sum < best) {
                                best = sum;
                                res = cur;
                            } else if(sum == best) {
                                if(res.compare(cur) > 0) res = cur;
                            }
                            
                        }
                    }
                }
            }
        }

        cout << res << " " << best << endl;
    }

    return 0;
}
