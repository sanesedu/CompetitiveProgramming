
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

int main() {

    string line;

    while(getline(cin,line)) {
        
        stack<int> S;
        
        long long int R, A, V;
        R = A = V = 0;
        
        for(unsigned int i = 0; i < line.length(); i++) {
            if(line[i] == 'R') { R++; S.push(0);}
            else if(line[i] == 'A' && A < R && S.top() != 1) { A++; S.push(1);}
            else if(line[i] == 'V' && R > 0 && A > 0 && S.top() == 1) { V++; R--; A--; S.pop(); S.pop();}
            else { R = A = 0; while(!S.empty()) S.pop();}
        }

        printf("%lld\n",V);
    }

    return 0;
}
