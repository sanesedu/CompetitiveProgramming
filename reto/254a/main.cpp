
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

    while(cin >> n) {
        if(n == 0) break;

        vector<int> people(n);
        vector<int> skis(n);
    
        fori(i, n) cin >> people[i];
        fori(i, n) cin >> skis[i];

        sort(all(people));
        sort(all(skis));
    
        long long sum = 0;

        fori(i, n) {
            sum += abs(people[i] - skis[i]);
        }

        cout << sum << endl;
    }

    return 0;
}
