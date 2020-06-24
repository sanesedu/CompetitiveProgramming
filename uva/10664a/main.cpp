
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int weight[25];
int memo[205][205];
int n;

int pack(int left, int state) {

    if(state == n) {
        return 0; 
    }

    if(memo[left][state] != -1) {
        return memo[left][state];
    }

    int a = 0;
    int b = 0;

    if(left - weight[state] >= 0) { //it is possible to take this suitcase
        a = pack(left - weight[state], state + 1) + weight[state];
    }

    b = pack(left, state + 1); //do not take this suitcase

    memo[left][state] = max(a, b);

    return memo[left][state];
}

int main() {

    int q, t;
    cin >> q;
    
    string line;

    getline(cin, line);

    while(q--) {
        getline(cin, line);
        
        int total_weight = 0;
        int index = 0;
       
        memset(weight, 0, sizeof(weight));
        memset(memo, -1, sizeof(memo));

        stringstream ss(line);

        while(!ss.eof()) {
            ss >> t;
            weight[index] = t;
            total_weight += t;
            index++;
        }

        if(total_weight % 2 == 1) {
            cout << "NO\n";
        } else {
            int aim = total_weight / 2;

            n = index;

            if(pack(aim, 0) == aim) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
