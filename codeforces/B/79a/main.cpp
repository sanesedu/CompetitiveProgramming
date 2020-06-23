
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

    set<pair<int, int> > st;

    int n, m, k, t, a, b, ans;
	cin >> n >> m >> k >> t;
	
    while(k--) {
		cin >> a >> b;
		st.insert({a, b});
	}

	while(t--) {
		cin >> a >> b;
		if (st.count({a, b})) { cout << "Waste" << endl; continue; }
		ans = ((a-1)*m) + b; //number of cells before this cell including it
		ans -= distance(st.begin(), st.lower_bound({a, b})); //number of waste cells before this cell + inmediately next one (lower bound, first element not less than)
		ans = (ans-1) % 3; //number of non-waste cells before this one % 3
		if (ans == 0) cout << "Carrots" << endl;
		else if (ans == 1) cout << "Kiwis" << endl;
		else cout << "Grapes" << endl;
	}

    return 0;
}
